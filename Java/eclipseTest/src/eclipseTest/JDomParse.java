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
	private String xmlpath;
	private SAXBuilder builder;
	public JDomParse(){
        xmlpath="resources/books.xml";
		builder=new SAXBuilder();	
	}
	public void printXML() {
		try {
			Document doc = builder.build(xmlpath);
			printDocument(doc);
		}catch (Exception e) {
			e.printStackTrace();
			// TODO: handle exception
		}
	}
	public void changeXML() {
		try {
			Document doc = builder.build(xmlpath);
			System.out.println("Before changing the XML file:");
			printDocument(doc);
			Element books = doc.getRootElement();
			List<Element> bookList = books.getChildren();
			for (Element e : bookList) {
				if (e.getChildTextTrim("name").equals("Lincon")) {
					e.getChild("price").setText("30.5");
				}
			}
			
			// add a new book
			Element newBook = new Element("book");
			Element newBookId = new Element("bookId").setText("5");
			Element newBookName = new Element("name").setText("The Story Of The Bible");
			Element newBookPrice = new Element("price").setText("39.0");
			
			newBook.addContent(newBookId);
			newBook.addContent(newBookName);
			newBook.addContent(newBookPrice);
			
			bookList.add(newBook);
			
			XMLOutputter outputter = new XMLOutputter();
			outputter.output(doc, new FileOutputStream(xmlpath));
			System.out.println("After changing the XML file:");
			printDocument(doc);
		} catch (Exception e) {
			// TODO: handle exception
			e.printStackTrace();
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
		JDomParse jDomParse = new JDomParse();
		
		jDomParse.printXML();
		//jDomParse.changeXML();
	}
}
