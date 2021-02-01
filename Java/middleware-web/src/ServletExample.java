import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;

public class ServletExample extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws IOException {
        req.setCharacterEncoding("UTF-8");
        resp.setContentType("text/html;charset=UTF-8");
        String name = req.getParameter("name");
        String password = req.getParameter("password");

        PrintWriter out = resp.getWriter();
        String html = "<html>\n" +
                "  <head>\n" +
                "    <title>middleware</title>\n" +
                "  </head>\n" +
                "  <body>";
        if (name != null || password != null){
            html += "<p>\n" +
                    "    你的姓名是：" + name + "<br>" +
                    "    你的密码是：" + password +
                    "  </p>";
        }
        html += "<form action=\"servletExample\" method=\"post\">\n" +
                "    姓名：<input type=\"text\" name=\"name\"><br>\n" +
                "    密码：<input type=\"password\" name=\"password\"><br>\n" +
                "    <input type=\"submit\" value=\"确认提交\">\n" +
                "  </form>\n" +
                "  </body>\n" +
                "</html>";
        out.print(html);
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        doGet(req,resp);
    }
}
