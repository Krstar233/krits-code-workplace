package designpattern.mvc;

public class MVCPatternDemo {
    public static void main(String[] args) {
        Student model = retrieveStudentFromDatabase();
        StudentView view = new StudentView();
        StudentController controller = new StudentController(model, view);

        controller.updateView();

        controller.setStudentName("Jack");

        controller.updateView();

    }
    public static Student retrieveStudentFromDatabase(){
        Student student = new Student();
        student.setName("Krits");
        student.setRollNo("10000");
        return student;
    }
}
