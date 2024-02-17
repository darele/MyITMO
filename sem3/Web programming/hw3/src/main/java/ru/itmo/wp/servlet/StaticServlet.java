package ru.itmo.wp.servlet;

import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.File;
import java.io.IOException;
import java.io.OutputStream;
import java.nio.file.Files;

public class StaticServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws IOException {
        String uriExtended = request.getRequestURI();
        String[] uris = uriExtended.split("\\+");
        File tempFile = findFile(uris[0]);
        if (tempFile != null) {
            response.setContentType(getServletContext().getMimeType(tempFile.getName()));
        } else {
            response.setContentType("text/html");
            //Whatever, response = 404 will take care of it :P
        }
        for (String uri : uris) {
            File file = findFile(uri);
            if (file != null) {
                try (OutputStream outputStream = response.getOutputStream()) {
                    Files.copy(file.toPath(), outputStream);
                }
            } else {
                response.sendError(HttpServletResponse.SC_NOT_FOUND);
            }
        }
    }

    private File findFile(String uri) {
        File file = new File(new File(getServletContext().getRealPath("./")).getParentFile().getParentFile(), "/src/main/webapp/static" + uri);
        if (file.isFile()) {
            return file;
        } else {
            file = new File(getServletContext().getRealPath("/static"), uri);
            if (file.isFile()) {
                return file;
            } else {
                return null;
            }
        }
    }
}
