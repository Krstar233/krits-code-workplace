package fun.krits;

import net.sf.json.JSONObject;

public class App {
	public static void main(String[] args) {
		  //jsonObject转换为JavaBean
		  String str = "{'name':'鸡蛋','price':8,'weight':1.3,'category':'禽蛋'}";
		  Product product4 = (Product) JSONObject.toBean(JSONObject.fromObject(str), Product.class);
		  System.out.println(product4);
	}
}
