public class RDAccount extends Account {

    private int noOfMonths, ageOfACHolder;
    private double monthlyAmount;

    public RDAccount(double amount, int noOfMonths, int ageOfACHolder, double monthlyAmount) {
        super(amount);
        this.noOfMonths = noOfMonths;
        this.ageOfACHolder = ageOfACHolder;
        this.monthlyAmount = monthlyAmount;
        super.setInterestRate(calculateInterest());
    }

    public double calculateInterest() {

        double i = 0;

        if (noOfMonths == 6)
            i = 7.50;
        else if (noOfMonths == 9)
            i = 7.75;
        else if (noOfMonths == 12)
            i = 8.00;
        else if (noOfMonths == 15)
            i = 8.25;
        else if (noOfMonths == 18)
            i = 8.50;
        else if (noOfMonths == 21)
            i = 8.75;

        return  ageOfACHolder > SENIOR_CITIZEN_LIMIT ? i + 0.5 : i;

    }

    public int getNoOfMonths() {
        return noOfMonths;
    }

    public void setNoOfMonths(int noOfMonths) {
        this.noOfMonths = noOfMonths;
    }

    public double getMonthlyAmount() {
        return monthlyAmount;
    }

    public void setMonthlyAmount(double monthlyAmount) {
        this.monthlyAmount = monthlyAmount;
    }

    public int getAgeOfACHolder() {
        return ageOfACHolder;
    }

    public void setAgeOfACHolder(int ageOfACHolder) {
        this.ageOfACHolder = ageOfACHolder;
    }
}
