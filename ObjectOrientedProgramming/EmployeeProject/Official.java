public class Official extends Employee{

	private String specialisation;

	public Official(
		String name, 
		String address,
		int age,
		double salary,
		String phoneNumber,
		String specialisation) {
		super(name, address, age, salary, phoneNumber);
		this.specialisation = specialisation;
	}
	
	public String getSpecialisation(){
		return specialisation;
	}
	
	public void setSpecialisation(){
		this.specialisation = specialisation;
	}
	
}
