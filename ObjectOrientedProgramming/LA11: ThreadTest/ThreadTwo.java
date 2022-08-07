public class ThreadTwo extends Thread {

    private volatile int i = 0;

    public void setInt(int i) {
        this.i = i;
    }

    @Override
    public void run() {
        super.run();

        System.out.println(
                "Square of " + i + " : " + (i * i)
        );

    }
}
