import java.util.Scanner;

public class TransposeTest {

	public static void main(String[] args) {
		
		Scanner scanner = new Scanner(System.in);
		
		int[][] arr = Transpose.getMatrix(scanner);
		
		System.out.println("Original Array: ");

		Transpose.printMatrix(arr);
		
		int[][] transpose = Transpose.findTranspose(arr);
		
		System.out.println("Transpose Array: ");
		
		Transpose.printMatrix(transpose);
		
	}
	
}
