import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Scanner;

public class Test {

    public static void main(String[] args) {

//        String[] arr = {"John Doe", "Jean Doe", "Elon Musk", "Satya Nadella", "Edward Snowden"};
//        int n = arr.length;

        Scanner scanner = new Scanner(System.in);

        int n;

        while (true) {

            try {

                System.out.print("Enter the number of elements in array: ");
                n = scanner.nextInt();
                break;

            } catch (InputMismatchException e) {

                System.out.println("Invalid number of elements");
                scanner.nextLine();

            }

        }

        scanner.nextLine();

        String[] arr = new String[n];

        for (int i = 0; i < n; i++) {
            System.out.print("Enter element number " + (i + 1) + ": ");
            arr[i] = scanner.nextLine();
        }

        scanner.close();

        System.out.println(
                "Initial array: " +
                        Arrays.toString(arr)
        );

        System.out.println(
                "Sorted array: " +
                        Arrays.toString(
                                QuickSort.quickSort(arr, 0, n - 1)
                        )
        );

    }

}

/*

Enter the number of elements in array: n
Invalid number of elements
Enter the number of elements in array: 5
Enter element number 1: John Doe
Enter element number 2: Jean Doe
Enter element number 3: Elon Musk
Enter element number 4: Satya Nadella
Enter element number 5: Edward Snowden
Initial array: [John Doe, Jean Doe, Elon Musk, Satya Nadella, Edward Snowden]
Sorted array: [Edward Snowden, Elon Musk, Jean Doe, John Doe, Satya Nadella]

Process finished with exit code 0

*/