import java.util.Random;
import java.util.Timer;
import java.util.TimerTask;

public class ThreadOne extends Thread {

    private final Generate generate;

    public ThreadOne(Generate generate) {
        this.generate = generate;
    }

    @Override
    public void run() {
        super.run();

        new Timer()
                .scheduleAtFixedRate(
                        new TimerTask() {
                            @Override
                            public void run() {
                                generate.processFinished(
                                        new Random().nextInt(100)
                                );
                            }
                        },
                        0,
                        1000
                );
    }

}
