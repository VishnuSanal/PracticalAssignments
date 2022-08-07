public class Test{
	
	public static void main(String[] args){

		print("\nTesting Person.java\n");
		Person person = new Person("Binu", "01/01/2001");
		print("Name: " + person.getName() + "\t" + "DOB: " + person.getDateOfBirth());
		
		person.setName("Cinu");
		person.setDateOfBirth("02/02/2002");
		print("Name: " + person.getName() + "\t" + "DOB: " + person.getDateOfBirth());
		
		print("\nTesting Teacher.java\n");
		Teacher teacher = new Teacher("Dinu", "03/03/2003", "1000000", "Mathematics");
		print("Name: " + teacher.getName() + "\t" + "DOB: " + teacher.getDateOfBirth() + "\t" +
			"Salary: " + teacher.getSalary() + "\t" + "Subject: " + teacher.getSubject()
			);
		
		teacher.setName("Jinu");
		teacher.setDateOfBirth("04/04/2004");
		teacher.setSalary("1500000");
		teacher.setSubject("LACA");
			
		print("Name: " + teacher.getName() + "\t" + "DOB: " + teacher.getDateOfBirth() + "\t" +
			"Salary: " + teacher.getSalary() + "\t" + "Subject: " + teacher.getSubject()
			);
		
		print("\nTesting Student.java\n");
		Student student = new Student("Kinu", "05/05/2005", "000CSE000");
		print("Name: " + student.getName() + "\t" + "DOB: " + student.getDateOfBirth() + "\t" +
			"StudentID: " + student.getStudentID()
			);
		
		student.setName("Linu");
		student.setDateOfBirth("06/06/2006");
		student.setStudentID("111CSE111");
		print("Name: " + student.getName() + "\t" + "DOB: " + student.getDateOfBirth() + "\t" +
			"StudentID: " + student.getStudentID()
			);
		
		print("\nTesting CollegeStudent.java\n");
		CollegeStudent collegeStudent = new CollegeStudent("Minu", "07/07/2007", "222CSE222", "MyAwesomeCollege", 1);
		print("Name: " + collegeStudent.getName() + "\t" + "DOB: " + collegeStudent.getDateOfBirth() + "\t" +
			"StudentID: " + collegeStudent.getStudentID() + "\t" + "CollegeName: "  + collegeStudent.getCollegeName() + "\t" +
			"Year: " + collegeStudent.getYear() + "\t"
			);
		
		collegeStudent.setName("Qinu");
		collegeStudent.setDateOfBirth("08/08/2008");
		collegeStudent.setStudentID("333CSE333");
		collegeStudent.setCollegeName("YourAwesomeCollege");
		collegeStudent.setYear(2);
		print("Name: " + collegeStudent.getName() + "\t" + "DOB: " + collegeStudent.getDateOfBirth() + "\t" +
			"StudentID: " + collegeStudent.getStudentID() + "\t" + "CollegeName: "  + collegeStudent.getCollegeName() + "\t" +
			"Year: " + collegeStudent.getYear() + "\t"
			);
		
	
	}
	
	static void print(String string){
		System.out.println(string);
	}
	
}
