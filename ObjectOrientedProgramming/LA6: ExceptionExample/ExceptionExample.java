public class ExceptionExample {
	
	public static void main(String[] args) {
		
	        try {
	        
        	    printInteger(args[0]);

        	} catch (Exception e) {
        	
        		if (e instanceof NullPointerException || e instanceof ArrayIndexOutOfBoundsException)	
	        		System.out.println("No command line args found");
	        	else if (e instanceof NumberFormatException)
	        		System.out.println("The given argument is not a valid number");
			else
				throw e;

	        } finally {
			System.out.println("Note: This program expects a number as the first command line argument");
	        }

	}

	private static void printInteger(String s) throws NumberFormatException {
	
		try {
	        
			System.out.println(
				"The given value is: " + Integer.valueOf(s)
			);

        	} catch (NumberFormatException e) {
			
			throw e;

	        }
	}
}
