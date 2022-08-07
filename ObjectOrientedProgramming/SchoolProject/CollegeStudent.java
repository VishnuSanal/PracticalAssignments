public class CollegeStudent extends Student{

	private String collegeName;
	private int year;
	
	public CollegeStudent(String name, String dateOfBirth, String studentID, String collegeName, int year){
		super(name, dateOfBirth, studentID);
		this.collegeName = collegeName;
		this.year = year;
	}
	
	public String getCollegeName(){
		return collegeName;
	}
	
	public void setCollegeName(String collegeName){
		this.collegeName = collegeName;
	}
	
	public int getYear(){
		return year;
	}

	public void setYear(int year){
		this.year = year;
	}
}
