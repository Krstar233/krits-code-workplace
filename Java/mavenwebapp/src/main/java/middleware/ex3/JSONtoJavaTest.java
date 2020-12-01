package middleware.ex3;

import net.sf.json.JSONArray;
import net.sf.json.JSONObject;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

class JSONtoJavaTest {
    private String javaObjToJSONstr(Student student){
        String name = student.getName();
        int age = student.getAge();
        String jsonStr = String.format("{\"name\":\"%s\",\"age\":%d}", name, age);
        //System.out.println(jsonStr);
        return jsonStr;
    }

    private String javaArrToJSONstr(List<Student> students){
        StringBuffer sb = new StringBuffer();
        sb.append("[");
        for (Iterator<Student> it = students.iterator(); it.hasNext();){
            sb.append(javaObjToJSONstr(it.next()));
            if (it.hasNext())
                sb.append(",");
        }
        sb.append("]");
        //System.out.println(sb);
        return sb.toString();
    }

    private Student jsonStrTojavaObj(String jsonStr){
        JSONObject jsonObject = JSONObject.fromObject(jsonStr);
        Student student = (Student) JSONObject.toBean(jsonObject, Student.class);
        //System.out.println(student);
        return student;
    }

    private List<Student> jsonStrToJavaArry(String jsonStr){
        List<Student> list = new ArrayList<>();
        JSONArray jsonArray = JSONArray.fromObject(jsonStr);
        for (Object obj : jsonArray){
            Student student = (Student) JSONObject.toBean((JSONObject) obj, NewStudent.class);
            list.add(student);
        }
        return list;
    }

    public static void main(String[] args) {
        JSONtoJavaTest test = new JSONtoJavaTest();

        Student student = new Student("方依依", 19);
        System.out.println(test.javaObjToJSONstr(student));

        Student student1 = new Student("吴东慰", 20);
        Student student2 = new Student("祝鹏岚", 21);
        Student student3 = new Student("刘清影", 21);
        List<Student> studentList = new ArrayList<>();
        studentList.add(student1);
        studentList.add(student2);
        studentList.add(student3);
        System.out.println(test.javaArrToJSONstr(studentList));

        String jsonStr1 = "{\"name\":\"方依依\",\"age\":17}";
        System.out.println(test.jsonStrTojavaObj(jsonStr1));

//        String jsonStr2 = "[{\"stuNo\":20170031, \"name\":\"何立立\"}, {\"stuNo\":20170032, \"name\":\"赵多多\"}]";
//        List<Student> list = test.jsonStrToJavaArry(jsonStr2);
//        for (Student stu : list){
//            System.out.println(stu);
//        }
    }
}
