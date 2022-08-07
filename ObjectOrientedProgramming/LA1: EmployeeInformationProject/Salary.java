public class Salary {

    private double salaryBasic, salaryHRA, salaryIT, salaryDA, salaryNet;

    public Salary(double salaryBasic, double salaryHRA, double salaryIT, char designation) {
        this.salaryBasic = salaryBasic;
        this.salaryHRA = salaryHRA;
        this.salaryIT = salaryIT;
        this.salaryDA = getDA(designation);
        this.salaryNet = salaryBasic + salaryHRA + salaryDA - salaryIT;
    }

    private double getDA(char designation) {

        switch (designation) {

            case 'e':
                return 20000;
            case 'c':
                return 32000;
            case 'k':
                return 12000;
            case 'r':
                return 15000;
            case 'm':
                return 40000;
            default:
                return 0;

        }

    }

    public double getSalaryBasic() {
        return salaryBasic;
    }

    public void setSalaryBasic(double salaryBasic) {
        this.salaryBasic = salaryBasic;
    }

    public double getSalaryHRA() {
        return salaryHRA;
    }

    public void setSalaryHRA(double salaryHRA) {
        this.salaryHRA = salaryHRA;
    }

    public double getSalaryIT() {
        return salaryIT;
    }

    public void setSalaryIT(double salaryIT) {
        this.salaryIT = salaryIT;
    }

    public double getSalaryDA() {
        return salaryDA;
    }

    public void setSalaryDA(double salaryDA) {
        this.salaryDA = salaryDA;
    }

    public double getSalaryNet() {
        return salaryNet;
    }

    public void setSalaryNet(double salaryNet) {
        this.salaryNet = salaryNet;
    }
}
