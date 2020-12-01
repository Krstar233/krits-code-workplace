package middleware.ex3;

public class NewStudent extends Student{
    private String stuNo;

    public String getStuNo() {
        return stuNo;
    }

    public void setStuNo(String stuNo) {
        this.stuNo = stuNo;
    }

    @Override
    public String toString() {
        return getName() + " " + getAge() + " " +getStuNo();
    }
}
