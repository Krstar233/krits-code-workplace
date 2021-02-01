package designpattern.mvc;

public class StudentController {
    private Student model;
    private StudentView view;

    public StudentController(Student model, StudentView view){
        this.model = model;
        this.view = view;
    }
    public void setStudentName(String stuName){
        model.setName(stuName);
    }
    public void setStudentRollNo(String stuRollNo){
        model.setRollNo(stuRollNo);
    }
    public String getStudentName(){
        return model.getName();
    }
    public String getStudentRollNo(){
        return model.getRollNo();
    }
    public void updateView(){
        view.printStudentDetails(model.getName(), model.getRollNo());
    }
}
