public class InterestCalculator {

    public static final int ACCOUNT_TYPE_SB = 0;
    public static final int ACCOUNT_TYPE_FD = 1;
    public static final int ACCOUNT_TYPE_RD = 2;

    /*
        A = P * (1 + (r/n)) ^ (n * t) //assume n == 1
    */

    public static double calculateInterest(FDAccount account) {
        return account.getAmount() * Math.pow(1 + account.getInterestRate(), account.getNoOfDays() / 365);
    }

    public static double calculateInterest(RDAccount account) {
        return account.getAmount() * Math.pow(1 + account.getInterestRate(), account.getNoOfMonths() / 12);
    }

    public static double calculateInterest(SBAccount account) {
        return account.getAmount() * Math.pow(1 + account.getInterestRate(), account.getYears());
    }
}
