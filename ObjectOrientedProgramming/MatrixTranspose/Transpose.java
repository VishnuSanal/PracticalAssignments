import java.util.Scanner;

public class Transpose {

	static int[][] getMatrix(Scanner scanner) {
		
		System.out.print("Number of rows of matrix: ");
 		int r = scanner.nextInt();
		
		System.out.print("Number of columns of matrix: ");
		int c = scanner.nextInt();
		
		int A[][] = new int[c][r], B[][] = new int[c][r];

		System.out.println("Enter the Matrix elements: ");
		
		for(int i = 0; i < c; i++) {
			for(int j = 0; j < r; j++) {
				System.out.print("Enter A" + (i + 1) + (j + 1) + ": ");
				A[i][j] = scanner.nextInt();
			}
		}
		
		return A;
		
		}
		
		static int[][] findTranspose(int[][] A) {
		
		int c = A.length, r = A[0].length;
		
		int B[][] =  new int[c][r];
		
		for(int i = 0; i < c; i++) {
			for(int j = 0; j < r; j++) {
				B[i][j] = A[j][i];
			}
		}
		
		return B;
		
		}
		
		static void printMatrix(int[][] A) {
		
		int c = A.length, r = A[0].length;
		
		for(int i = 0; i < c; i++) {
			for(int j = 0; j < r; j++) {
				System.out.print("\tA" + (i + 1) + (j + 1) + ": " + A[i][j]);
			}
			System.out.println();
		}
		
		}
			
	}
