public class Test {

    public static void main(String[] args) {

        Value value = new Value();

        for (int i = 0; i < 10; i++) {

            new Thread(
                    new Runnable() {
                        @Override
                        public void run() {
                            value.incrementValue();
                        }
                    }
            ).start();

        }
    }
}
