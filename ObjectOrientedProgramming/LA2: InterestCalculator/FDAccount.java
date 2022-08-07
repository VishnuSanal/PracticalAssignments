public class FDAccount extends Account {

    private int noOfDays, ageOfACHolder;

    public FDAccount(double amount, int noOfDays, int ageOfACHolder) {
        super(amount);
        this.noOfDays = noOfDays;
        this.ageOfACHolder = ageOfACHolder;
        super.setInterestRate(calculateInterest());
    }

    public double calculateInterest() {

        if (getAmount() < 10000000) {

            double i = 0;

            if (noOfDays > 7 && noOfDays < 14)
                i = 4.50;
            else if (noOfDays > 15 && noOfDays < 29)
                i = 4.75;
            else if (noOfDays > 30 && noOfDays < 45)
                i = 5.50;
            else if (noOfDays > 45 && noOfDays < 60)
                i = 7;
            else if (noOfDays > 61 && noOfDays < 184)
                i = 7.50;
            else if (noOfDays > 185)
                i = 8.00;

            return ageOfACHolder > SENIOR_CITIZEN_LIMIT ? i + 0.5 : i;

        } else {

            if (noOfDays > 7 && noOfDays < 14)
                return 6.50;
            if (noOfDays > 15 && noOfDays < 29)
                return 6.75;
            if (noOfDays > 30 && noOfDays < 45)
                return 6.75;
            if (noOfDays > 45 && noOfDays < 60)
                return 8;
            if (noOfDays > 61 && noOfDays < 184)
                return 8.50;

            return 10.00;

        }

    }

    public int getNoOfDays() {
        return noOfDays;
    }

    public void setNoOfDays(int noOfDays) {
        this.noOfDays = noOfDays;
    }

    public int getAgeOfACHolder() {
        return ageOfACHolder;
    }

    public void setAgeOfACHolder(int ageOfACHolder) {
        this.ageOfACHolder = ageOfACHolder;
    }
}
