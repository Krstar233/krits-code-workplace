package middleware.ex2;

public class Student {
	private String studentNo;
	private String name;
	private String gender;
	private String specialty;
	
	public Student() {
		// TODO Auto-generated constructor stub
	}
	public Student(String studentNo, String name, String gender, String specialty) {
		super();
		this.studentNo = studentNo;
		this.name = name;
		this.gender = gender;
		this.specialty = specialty;
	}
	public String getStudentNo() {
		return studentNo;
	}
	public void setStudentNo(String studentNo) {
		this.studentNo = studentNo;
	}
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public String getGender() {
		return gender;
	}
	public void setGender(String gender) {
		this.gender = gender;
	}
	public String getSpecialty() {
		return specialty;
	}
	public void setSpecialty(String specialty) {
		this.specialty = specialty;
	}
	@Override
	public String toString() {
		// TODO Auto-generated method stub
		return studentNo + " " + name + " " + gender + " " + specialty;
	}
}