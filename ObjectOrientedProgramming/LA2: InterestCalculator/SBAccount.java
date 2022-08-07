public class SBAccount extends Account {

    private static final int SB_NORMAL_ACCOUNT = 0;
    private static final int SB_NRI_ACCOUNT = 1;

    private int type, years;

    public SBAccount(double amount, int type, int years) {
        super(amount);
        this.type = type;
        this.years = years;
        super.setInterestRate(calculateInterest());
    }

    public double calculateInterest() {
        return type == SB_NORMAL_ACCOUNT ? 4 : 6;
    }

    public int getType() {
        return type;
    }

    public void setType(int type) {
        this.type = type;
    }

    public int getYears() {
        return years;
    }

    public void setYears(int years) {
        this.years = years;
    }
}