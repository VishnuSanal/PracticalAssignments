import java.util.InputMismatchException;
import java.util.Scanner;

public class VideoLauncher {

    /*

    * Would a member variable named “VideoID” been useful in this class design?
        - Yes. It can be used as a primary key. Using the name as identifier is not a good practice.
    * If yes, what ideas could be used for auto-generating the “VideoID”?
        - Declare VideoID as a static variable in the class Video & increment it in the constructor.
    * What other changes in the above features could have made the user-experience better?
        - I would prefer to display the menu once cuz I think the current implementation is cumbersome.

    */

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        while (true) {

            System.out.println(
                    "MAIN MENU\n" +
                            "=========\n" +
                            "1. Add Videos:\n" +
                            "2. Check Out Video :\n" +
                            "3. Return Video :\n" +
                            "4. Receive Rating :\n" +
                            "5. List Inventory :\n" +
                            "6. Exit :\n"
            );

            int choice;

            try {
                System.out.println("Enter your option (1..6): ");
                choice = scanner.nextInt();
            } catch (InputMismatchException e) {
                System.out.println("Please enter a valid input\n");
                scanner.nextLine();
                continue;
            }

            if (choice == 1) {

                System.out.print("Enter the name of the video you want to add: ");
                String name = scanner.next();
                VideoStore.addVideo(name);

            } else if (choice == 2) {

                System.out.print("Enter the name of the video you want to check out: ");
                String name = scanner.next();
                VideoStore.doCheckout(name);

            } else if (choice == 3) {

                System.out.print("Enter the name of the video you want to Return: ");
                String name = scanner.next();
                VideoStore.doReturn(name);

            } else if (choice == 4) {

                System.out.print("Enter the name of the video you want to Rate: ");
                String name = scanner.next();
                System.out.print("Enter the rating for this video: ");
                int rating = scanner.nextInt();
                VideoStore.receiveRating(name, rating);

            } else if (choice == 5) {

                VideoStore.listInventory();

            } else if (choice == 6) {

                System.out.println("Exiting...!! Thanks for using the application.");
                System.exit(0);

            } else {

                System.out.println("Please enter a valid choice!");

            }

        }
    }

}
