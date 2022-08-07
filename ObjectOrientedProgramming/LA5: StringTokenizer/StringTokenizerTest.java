import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.StringTokenizer;

public class StringTokenizerTest {

    public static void main(String[] args) {

        try {

            int sum = 0;

            StringTokenizer stringTokenizer = new StringTokenizer(
                    read(
                            "read.txt"
                    )
            );

            while (stringTokenizer.hasMoreTokens()) {

                String i = stringTokenizer.nextToken();
                sum += Integer.parseInt(i);
                System.out.print(i + "\t");

            }

            System.out.println("\nSum: " + sum);

        } catch (Exception e) {

            if (e instanceof NumberFormatException)
                System.out.println("\nWrong Structure: The file doesn't contain only numbers");

            e.printStackTrace();
        }

    }

    private static String read(String path) throws IOException {

        BufferedReader bufferedReader = null;
        StringBuilder stringBuilder = new StringBuilder();

        try {

            bufferedReader = new BufferedReader(new FileReader(path));

            String line = null;

            while ((line = bufferedReader.readLine()) != null)
                stringBuilder.append(line);

            return stringBuilder.toString();

        } catch (IOException e) {

            if (e instanceof FileNotFoundException)
                System.out.println("Requested read file not found");

            throw e;

        } finally {

            if (bufferedReader != null)
                bufferedReader.close();

        }
    }

}
