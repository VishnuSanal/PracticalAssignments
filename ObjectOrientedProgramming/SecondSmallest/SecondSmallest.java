import java.util.Scanner;

public class SecondSmallest {

	static int[] readArray() {
		
		Scanner scanner = new Scanner(System.in);
		
		System.out.print("Enter the size of array: ");
		int n = scanner.nextInt();
		
		int arr[] = new int[n];
		
		for(int i = 0; i < n; i++) {
			System.out.print("Enter element " + (i + 1) + ": ");
			arr[i] = scanner.nextInt();
		}
		
		return arr;
	
	}

	static void findSecondSmallest(int[] arr) {

		int small = Math.min(arr[0], arr[1]), second = Math.max(arr[0], arr[1]);

		for(int i = 2; i < arr.length; i++) {
		
			if(arr[i] <= small) {
			
				if(arr[i] != small)
					second = small;
				small = arr[i];
				continue;
			
			} 
			
			if (arr[i] < second){
				second = arr[i];
			}
		}
		
		System.out.println("Second: " + second + " Small: " + small);
	}

}
