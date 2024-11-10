package assignment_two_pipes;

import java.io.PipedInputStream;
import java.io.PipedOutputStream;

public class PipeExample {
    public static void main(String[] args) throws Exception {
        PipedInputStream pipedInputStream = new PipedInputStream();
        PipedOutputStream pipedOutputStream = new PipedOutputStream(pipedInputStream);

        new ProducerThread(pipedOutputStream).start();
        new ConsumerThread(pipedInputStream).start();
    }
}