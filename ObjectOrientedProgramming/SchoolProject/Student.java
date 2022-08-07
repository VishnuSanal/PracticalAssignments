public class Student extends Person{

	private String studentID;
	
	public Student(String name, String dateOfBirth, String studentID){
		super(name, dateOfBirth);
		this.studentID = studentID;
	}

	public String getStudentID(){
		return studentID;
	}
	
	public void setStudentID(String studentID){
		this.studentID = studentID;
	}
	
}
