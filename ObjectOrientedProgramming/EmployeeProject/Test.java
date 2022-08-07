public class Test {

	public static void printSalaryOfEmployee(Employee employee){
		employee.printSalary();
	}

	public static void main(String[] args) {

		Employee manager = new Manager(
			"John Doe",
			"House Name, Street Name, Lane Number, Town, City",
			25,
			480000,
			"9025874971",
			"R&D Department"
		);
		
		printSalaryOfEmployee(manager);
		
		Employee official = new Official(
			"Jean Doe",
			"House Name, Street Name, Lane Number, Town, City",
			24,
			640000,
			"8745921323",
			"Android Development"
		);
		
		printSalaryOfEmployee(official);
		
	}

}
