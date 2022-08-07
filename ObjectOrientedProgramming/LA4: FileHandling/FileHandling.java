import java.io.*;

public class FileHandling {

    public static void main(String[] args) {

        try {

            String read = readFromFile("read.txt");

            writeToFile("write.txt", read);

        } catch (IOException e) {
            e.printStackTrace();
        }

    }

    private static String readFromFile(String path) throws IOException {

        BufferedReader bufferedReader = null;

        try {

            bufferedReader = new BufferedReader(new FileReader(path));

            StringBuilder stringBuilder = new StringBuilder();

            String line = null;

            while ((line = bufferedReader.readLine()) != null) {
                stringBuilder.append(line);
            }

            System.out.println("File successfully read");

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

    private static void writeToFile(String path, String s) throws IOException {

        BufferedWriter bufferedWriter = null;

        try {

            bufferedWriter = new BufferedWriter(new FileWriter(path));

            bufferedWriter.write(s);

            System.out.println("File successfully written. Please check output file");

        } finally {

            if (bufferedWriter != null)
                bufferedWriter.close();

        }

    }

}
