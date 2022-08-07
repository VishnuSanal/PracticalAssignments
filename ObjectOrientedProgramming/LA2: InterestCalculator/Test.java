import java.util.InputMismatchException;
import java.util.Scanner;

public class Test {

    public static void main(String[] args) throws InvalidInputException {

        Scanner scanner = new Scanner(System.in);

        System.out.println(
                "MAIN MENU\n" +
                        "---------\n" +
                        "1.Interest Calculator – SB\n" +
                        "2. Interest Calculator –FD\n" +
                        "3. Interest Calculator –RD\n" +
                        "4. Exit"
        );

        try {

            System.out.print("Enter your option (1..4): ");
            int choice = scanner.nextInt();

            if (choice == InterestCalculator.ACCOUNT_TYPE_SB) {

                System.out.print("Enter the Average amount in your account: ");
                double amount = scanner.nextDouble();

                System.out.print("Enter the amount of years: ");
                int years = scanner.nextInt();

                System.out.println(
                        "Enter your account type" +
                                "1.Normal\n" +
                                "2. NRI\n"
                );
                int type = scanner.nextInt();

                SBAccount account = new SBAccount(amount, type, years);

                System.out.println(
                        "Interest gained: Rs. " +
                                InterestCalculator.calculateInterest(account)
                );


            } else if (choice == InterestCalculator.ACCOUNT_TYPE_FD) {

                System.out.print("Enter the FD amount: ");
                double amount = scanner.nextDouble();

                System.out.print("Enter the number of days: ");
                int days = scanner.nextInt();

                System.out.print("Enter your age: ");
                int age = scanner.nextInt();

                FDAccount account = new FDAccount(amount, days, age);

                System.out.println(
                        "Interest gained: Rs. " +
                                InterestCalculator.calculateInterest(account)
                );

            } else if (choice == InterestCalculator.ACCOUNT_TYPE_RD) {

                System.out.print("Enter the RD amount: ");
                double amount = scanner.nextDouble();

                System.out.print("Enter the number of months: ");
                int months = scanner.nextInt();

                System.out.print("Enter your age: ");
                int age = scanner.nextInt();

                System.out.print("Enter the monthly RD amount: ");
                double monthlyAmount = scanner.nextDouble();

                RDAccount account = new RDAccount(amount, months, age, monthlyAmount);

                System.out.println(
                        "Interest gained: Rs. " +
                                InterestCalculator.calculateInterest(account)
                );

            } else
                throw new InvalidInputException("Please enter a valid value as input");
        } catch (InputMismatchException e) {
            throw new InvalidInputException("Please enter a valid value as input");
        }

    }

}
