package eclipseTest;


import java.io.FileOutputStream;
import java.io.IOException;
import java.util.Iterator; 
import java.util.List; 

import org.jdom2.Document; 
import org.jdom2.Element;
import org.jdom2.JDOMException; 
import org.jdom2.input.SAXBuilder; 
import org.jdom2.output.XMLOutputter; 


public class JDomParse {
	public JDomParse(){ 
        String xmlpath="resources/books.xml";
		SAXBuilder builder=new SAXBuilder();		
		try {
			Document doc=builder.build(xmlpath);
			System.out.println("Before change prices:");
			printDocument(doc);
			Element books=doc.getRootElement();
		    List<Element> booklist = books.getChildren("book");
		    for (Element e : booklist) {
		    	Double price = Double.parseDouble(e.getChildTextTrim("price"));
		    	price += 20;
		    	e.getChild("price").setText(price.toString());
		    }
		    System.out.println("After change prices:");
		    printDocument(doc);
			//XMLOutputter outputter=new XMLOutputter();
			//outputter.output(doc,new FileOutputStream(xmlpath));
		} catch (JDOMException e) {
			e.printStackTrace();     
		} catch (IOException e) {
			e.printStackTrace();
		} catch (Exception e) {
			e.printStackTrace();
			// TODO: handle exception
		}
	}
	private void printDocument(Document doc) throws Exception{
		Element books = doc.getRootElement();
		List<Element> bookList = books.getChildren("book");
		Iterator<Element> iter = bookList.iterator();
		while (iter.hasNext()) {
			Element book = (Element) iter.next();
			String id = book.getChildTextTrim("bookId");
			System.out.println(id);
			String name = book.getChildTextTrim("name");
			System.out.println(name);
			String price = book.getChildTextTrim("price");
			System.out.println(price);
		}
		System.out.println("==============");
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new JDomParse();
	}

}
