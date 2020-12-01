package middleware.ex3;

public class StudentWithStuNo extends Student{
    private String stuNo;

    public String getStuNo() {
        return stuNo;
    }

    public void setStuNo(String stuNo) {
        this.stuNo = stuNo;
    }

    @Override
    public String toString() {
        return getName() + " " +getStuNo();
    }
}
