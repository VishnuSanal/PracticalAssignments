public class Manager extends Employee{

	private String department;

	public Manager(
		String name, 
		String address,
		int age,
		double salary,
		String phoneNumber,
		String department) {
		super(name, address, age, salary, phoneNumber);
		this.department = department;
	}
	
	public String getDepartment(){
		return department;
	}
	
	public void setDepartment(){
		this.department = department;
	}
	
}
