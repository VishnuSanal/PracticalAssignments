public class ThreadThree extends Thread {

    private volatile int i = 0;

    public void setInt(int i) {
        this.i = i;
    }

    @Override
    public void run() {
        super.run();

        System.out.println(
                "Cube of " + i + " : " + (i * i * i)
        );

    }
}
