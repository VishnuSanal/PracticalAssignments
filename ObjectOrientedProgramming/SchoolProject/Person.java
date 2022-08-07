public class Person{
	
	private String name, dateOfBirth;

	public Person(String name, String dateOfBirth){
		this.name = name;
		this.dateOfBirth = dateOfBirth;
	}
		
	public String getDateOfBirth(){
		return dateOfBirth;
	}
	
	public void setDateOfBirth(String dateOfBirth){
		this.dateOfBirth = dateOfBirth;
	}
	
	public String getName(){
		return name;
	}
	
	public void setName(String name){
		this.name = name;
	}
	
}
