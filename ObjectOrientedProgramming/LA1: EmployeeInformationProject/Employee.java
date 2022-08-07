public class Employee {

    private int empNum;
    private String name, joinDate, dept;
    private char designation;
    private Salary salary;

    public Employee(int empNum, String name, String joinDate, String dept, char designation, double salaryBasic, double salaryHRA, double salaryIT) {
        this.empNum = empNum;
        this.name = name;
        this.joinDate = joinDate;
        this.dept = dept;
        this.designation = designation;
        this.salary = new Salary(salaryBasic, salaryHRA, salaryIT, designation);
    }

    public int getEmpNum() {
        return empNum;
    }

    public void setEmpNum(int empNum) {
        this.empNum = empNum;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getJoinDate() {
        return joinDate;
    }

    public void setJoinDate(String joinDate) {
        this.joinDate = joinDate;
    }

    public String getDept() {
        return dept;
    }

    public void setDept(String dept) {
        this.dept = dept;
    }

    public char getDesignation() {
        return designation;
    }

    public void setDesignation(char designation) {
        this.designation = designation;
    }

    public Salary getSalary() {
        return salary;
    }

    public void setSalary(Salary salary) {
        this.salary = salary;
    }
}
