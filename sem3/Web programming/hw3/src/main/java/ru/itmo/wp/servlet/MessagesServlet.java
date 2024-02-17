package ru.itmo.wp.servlet;

import com.google.gson.Gson;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.HashMap;
import java.util.LinkedHashMap;
import java.util.LinkedList;

public class MessagesServlet extends HttpServlet {
    private LinkedList<LinkedHashMap<String, String>> datos = new LinkedList<>();
    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        String type = request.getRequestURI();
        String user = "";
        response.setContentType("application/json");
        switch (type) {
            case ("/message/auth"):
                String ans = "";
                if (request.getSession().getAttribute("user") == null) {
                    datos.clear();
                    if (request.getParameter("user") != null && !(request.getParameter("user").replace(" ", "").equals(""))) {
                        ans = request.getParameter("user");
                        request.getSession().setAttribute("user", request.getParameter("user"));
                    }
                } else {
                    ans = request.getSession().getAttribute("user").toString();
                }
                response.getWriter().print(new Gson().toJson(ans));
                response.getWriter().flush();
                break;
            case ("/message/add"):
                String message = request.getParameter("text");
                if (message != null && !(message.replace(" ", "").equals(""))) {
                    user = request.getSession().getAttribute("user").toString();
                    datos.add(new LinkedHashMap<>());
                    datos.get(datos.size() - 1).put("user", user);
                    datos.get(datos.size() - 1).put("text", message);
                    response.getWriter().write("");
                    response.getWriter().flush();
                }
                break;
            case("/message/findAll"):
                if (request.getSession().getAttribute("user") == null) {
                    datos.clear();
                }
                String json = new Gson().toJson(datos);
                response.getWriter().print(json);
                response.getWriter().flush();
                break;
            default:
                response.setStatus(HttpServletResponse.SC_NO_CONTENT);
                break;
        }
    }
}