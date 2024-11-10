package assignment_two_pipes;

import java.io.IOException;
import java.io.PipedInputStream;

public class ConsumerThread extends Thread {

    public ConsumerThread(PipedInputStream pipedInputStream) {
        super(() -> consumeData(pipedInputStream));
    }

    private static void consumeData(PipedInputStream pipedInputStream) {
        try {
            int i;
            while ((i = pipedInputStream.read()) != -1) {
                System.out.println("Consumed: " + i);
            }

            pipedInputStream.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
