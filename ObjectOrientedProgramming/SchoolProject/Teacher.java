public class Teacher extends Person{
	private String salary, subject;
	
	public Teacher(String name, String dateOfBirth, String salary, String subject){
		super(name, dateOfBirth);
		this.salary = salary;
		this.subject = subject;
	}

	public String getSalary(){
		return salary;
	}
	
	public void setSalary(String salary){
		this.salary = salary;
	}
	
	public String getSubject(){
		return subject;
	}
	
	public void setSubject(String subject){
		this.subject = subject;
	}
	
}
