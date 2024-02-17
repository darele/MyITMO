package ru.itmo.wp.servlet;

import ru.itmo.wp.util.ImageUtils;

import javax.servlet.FilterChain;
import javax.servlet.ServletException;
import javax.servlet.http.HttpFilter;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.OutputStream;
import java.util.Objects;

public class CaptchaFilter extends HttpFilter {
    private int randGen() {
        return ((int) (Math.random() * 900) + 99);
    }

    @Override
    protected void doFilter(HttpServletRequest request, HttpServletResponse response, FilterChain chain) throws IOException, ServletException {
        String uri = request.getRequestURI();
        if ("/captcha/pic".equals(uri)) {
            response.setContentType("image/png");
            OutputStream os = response.getOutputStream();
            os.write(ImageUtils.toPng(request.getSession().getAttribute("Captcha-Value").toString()));
            os.close();
        } else {
            //We have been redirected from an incorrect answer
            if (Objects.equals(request.getMethod(), "POST")) {
                //Two possible answers
                if (Objects.equals(request.getParameter("captcha"),
                        request.getSession().getAttribute("Captcha-Value").toString())) {
                    // right
                    //Then let's inform session that we have passed the filter successfully
                    request.getSession().setAttribute("Captcha-Status", 2);
                    response.sendRedirect(request.getSession().getAttribute("URI").toString());
                } else {
                    // wrong
                    //Let's go through the filter again with a new value
                    request.getSession().setAttribute("Captcha-Value", randGen());
                    response.sendRedirect("/captcha.html");
                }
            } else {
                // tab opening
                if (request.getSession().getAttribute("Captcha-Status") == null) {
                    //Session has just began, let's generate the captcha filter
                    request.getSession().setAttribute("Captcha-Status", 1);
                    request.getSession().setAttribute("Captcha-Value", randGen());
                    request.getSession().setAttribute("URI", uri);
                    response.sendRedirect("/captcha.html");
                    chain.doFilter(request, response);
                } else {
                    //Session began on another tab
                    //Let's check if we successfully passed captcha
                    request.getSession().setAttribute("Captcha-Value", randGen());
                    if (Objects.equals(request.getSession().getAttribute("Captcha-Status").toString(), "1")
                            && !Objects.equals(uri, "/captcha.html")) {
                        //If not passed, let's show it to the user
                        response.sendRedirect("/captcha.html");
                    }
                    chain.doFilter(request, response);
                }
            }
        }
    }
}
