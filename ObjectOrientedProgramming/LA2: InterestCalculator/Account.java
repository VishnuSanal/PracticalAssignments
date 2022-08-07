public abstract class Account {

    static final int SENIOR_CITIZEN_LIMIT = 60;

    private double interestRate, amount;

    public Account(double amount) {
        this.amount = amount;
    }

    public abstract double calculateInterest();

    public double getInterestRate() {
        System.out.println("getInterestRate()" + interestRate);
        return interestRate;
    }

    public void setInterestRate(double interestRate) {
        this.interestRate = interestRate;
    }

    public double getAmount() {
        return amount;
    }

    public void setAmount(double amount) {
        this.amount = amount;
    }
}
