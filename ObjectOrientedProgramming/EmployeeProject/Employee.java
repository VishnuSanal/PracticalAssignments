public class Employee{
	
	private String name, address, phone_Number;
	private int age;
	private double salary;
	
	public Employee(
		String name, 
		String address,
		int age,
		double salary,
		String phone_Number) {

		this.name = name;
		this.address = address;
		this.age  = age;
		this.salary = salary;
		this.phone_Number = phone_Number;
		
	}
	
	public String getName(){
		return name;
	}
	
	public String getAddress(){
		return address;
	}

	public String getPhone_Number(){
		return phone_Number;
	}
	
	public int getAge(){
		return age;
	}
	
	public double getSalary(){
		return salary;
	}
	
	public void setName(String name){
		this.name = name;
	}
	
	public void setAddress(String address){
		this.address = address;
	}
	
	public void setPhone_Number(String phone_Number){
		this.phone_Number = phone_Number;
	}
	
	public void setAge(int age){
		this.age = age;
	}
	
	public void setSalary(double salary){
		this.salary = salary;
	}

	public final void printSalary() {
		System.out.println("Salary: " + this.salary);
	}

}
