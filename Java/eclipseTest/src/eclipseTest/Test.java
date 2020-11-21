package eclipseTest;

import net.sf.json.JSONObject;

public class Test {
	public static void main(String[] args) {
		  //jsonObject×ª»»ÎªJavaBean
		  String str = "{'name':'¼¦µ°','price':8,'weight':1.3,'category':'ÇÝµ°'}";
		  Product product4 = (Product) JSONObject.toBean(JSONObject.fromObject(str), Product.class);
		  System.out.println(product4);
	}
}
