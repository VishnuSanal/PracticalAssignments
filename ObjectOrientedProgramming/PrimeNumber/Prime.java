import java.util.Scanner;

public class Prime {

	static int readInt() {

		System.out.print("Enter a number: ");
	
		return new Scanner(System.in).nextInt();
	}
	
	static boolean isPrime(int n) {

		for(int i = 2; i <= Math.sqrt(n); i++)
			if(n % i == 0)
				return false;
	
		return true;
	}

}
