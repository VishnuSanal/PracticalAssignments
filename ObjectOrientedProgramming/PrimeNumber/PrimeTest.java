public class PrimeTest {

	public static void main(String[] args) {

	int n = Prime.readInt();
	
	if(n == 1) {
		System.out.println("Neither prime nor composite");
		return;
	}
		
	
	System.out.println("The given number " + n + " is" + (Prime.isPrime(n) ? " " : " not ") + "prime");
	
	}
	
}
