<%@ page language="java" contentType="text/html; charset=UTF-8"
         pageEncoding="UTF-8" import="java.util.*" isELIgnored="false"%>
<%@ page import="reflect.Book" %>
<%
    List<String> words = new ArrayList<String>();
    words.add("today");
    words.add("is");
    words.add("a");
    words.add("great");
    words.add("day");
%>

<table width="200px" align="center" border="1" cellspacing="0">

    <%for (String word : words) {%>

    <tr>
        <td><%=word%></td>
    </tr>

    <%}%>

</table>

<%
    Book book = new Book("my life", "kr1");
    request.setAttribute("book", book);
%>

<h1>
    BOOK: ${book.name}, ${book.author}<br>
    ${book.author eq "kr" ? "Written by Krits" : "Unknown Author"}
</h1>