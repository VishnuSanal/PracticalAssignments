public class Test {

    public static void main(String[] args) {

        if (args == null || args.length == 0) {
            System.out.println("Search Failed: No command line args found");
            return;
        }

        try {

            System.out.println(
                    EmployeeInfo.search(Integer.parseInt(args[0]))
            );

        } catch (NumberFormatException e) {
            System.out.println("Search Failed: The given argument is not a valid number");
        }

    }
}
