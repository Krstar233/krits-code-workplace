package designpattern.mvc;

public class StudentView {
    public void printStudentDetails(String studentName, String studentRollno){
        System.out.println("Student:");
        System.out.println("Name: " + studentName);
        System.out.println("Roll No: " + studentRollno);
    }
}
