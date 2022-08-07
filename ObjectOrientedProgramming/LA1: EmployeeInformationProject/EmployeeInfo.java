public class EmployeeInfo {

    static String search(int query) {

        for (Employee e : getEmployeeList()) {
            if (e.getEmpNum() == query) {

                return "Emp No.\tEmp Name\tDepartment\tDesignation\tSalary"
                        + "\n" +
                        e.getEmpNum() + "\t" +
                        e.getName() + "\t\t" +
                        e.getDept() + "\t\t\t" +
                        e.getDesignation() + "\t" +
                        e.getSalary().getSalaryNet();

            }
        }

        return "There is no employee with empid :" + query;

    }

    static Employee[] getEmployeeList() {
        return new Employee[]{
                new Employee(1001, "Ashish", "01/04/2009", "R&D", 'e', 20000, 8000, 3000),
                new Employee(1002, "Sushma", "23/08/2012", "PM", 'c', 30000, 12000, 9000),
                new Employee(1003, "Rahul", "12/11/2008", "Acct", 'k', 10000, 8000, 1000),
                new Employee(1004, "Chahat", "29/01/2013", "Front Desk", 'r', 12000, 6000, 2000),
                new Employee(1005, "Ranjan", "16/07/2005", "Engg", 'm', 50000, 20000, 20000),
                new Employee(1006, "Suman", "1/1/2000", "Manufacturing", 'e', 23000, 9000, 4400),
                new Employee(1007, "Tanmay", "12/06/2006", "PM", 'c', 29000, 12000, 10000)
        };
    }
}
