import java.util.Scanner;

public class ReverseString {

	static String readString() {
		
		Scanner scanner = new Scanner(System.in);
		
		System.out.print("Enter the string: ");
		
		return scanner.nextLine();
	
	}

	static String reverseString(String string) {

		int s = 0, e = string.length() - 1;
		
		char arr[] = string.toCharArray();

		while(s < e) {
			char c = arr[s];
			arr[s++] = arr[e];
			arr[e--] = c;
		}
		
		return String. valueOf(arr);
	}

}
