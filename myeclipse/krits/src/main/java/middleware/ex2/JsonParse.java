package middleware.ex2;

import java.io.*;

import net.sf.json.JSONArray;
import net.sf.json.JSONObject;


public class JsonParse {
	public JsonParse() {
		// TODO Auto-generated constructor stub
		try(FileInputStream fileInputStream = new FileInputStream(new File("./resources/student.json"))){
			byte[] data = new byte[fileInputStream.available()];
			fileInputStream.read(data);
			String 
			JSONObject jsonObj = JSONObject.fromObject(data);
			JSONArray students = JSONArray.fromObject(jsonObj.get("students"));
			for (Object student : students) {
				Student stu = (Student) JSONObject.toBean((JSONObject)student, Student.class);
				System.out.println(stu);
			}
		}catch (Exception e) {
			// TODO: handle exception
			e.printStackTrace();
		}
	}
	public static void main(String[] args) {
		new JsonParse();
	}
}