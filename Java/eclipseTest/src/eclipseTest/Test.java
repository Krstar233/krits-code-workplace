package eclipseTest;

import net.sf.json.JSONObject;

public class Test {
	public static void main(String[] args) {
		  //jsonObjectת��ΪJavaBean
		  String str = "{'name':'����','price':8,'weight':1.3,'category':'�ݵ�'}";
		  Product product4 = (Product) JSONObject.toBean(JSONObject.fromObject(str), Product.class);
		  System.out.println(product4);
	}
}
