package assignment_two_pipes;

import java.io.IOException;
import java.io.PipedOutputStream;

public class ProducerThread extends Thread {

    public ProducerThread(PipedOutputStream pipedOutputStream) {
        super(() -> produceData(pipedOutputStream));
    }

    private static void produceData(PipedOutputStream pipedOutputStream) {
        try {
            for (int i = 0; i < 10; i++) {

                int data = (int) (Math.random() * 100);

                pipedOutputStream.write((byte) data);
                pipedOutputStream.flush();

                System.out.println("Produced: " + data);

                Thread.sleep(data % 100);
            }

            pipedOutputStream.close();
        } catch (InterruptedException | IOException e) {
            e.printStackTrace();
        }
    }
}
