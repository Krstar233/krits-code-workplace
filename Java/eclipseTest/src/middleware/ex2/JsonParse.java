package middleware.ex2;

import java.io.*;
import net.sf.json.JSONArray;
import net.sf.json.JSONObject;


public class JsonParse {
	public JsonParse() {
		// TODO Auto-generated constructor stub
		try(FileInputStream fileInputStream = new FileInputStream(new File("./resources/student.json"))){
			String json = new String(fileInputStream.readAllBytes());
			JSONObject jsonObj = JSONObject.fromObject(json);
			JSONArray students = JSONArray.fromObject(jsonObj.get("students"));
			for (Object student : students) {
				Student stu = (Student) JSONObject.toBean((JSONObject)student, Student.class);
				//System.out.println(student.getClass());
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
