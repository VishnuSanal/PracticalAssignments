public class Test {

    public static void main(String[] args) {

        ThreadOne threadOne = new ThreadOne((int i) -> {

            if (i % 2 == 0) {

                ThreadTwo threadTwo = new ThreadTwo();
                threadTwo.setInt(i);
                threadTwo.start();

            } else {

                ThreadThree threadThree = new ThreadThree();
                threadThree.setInt(i);
                threadThree.start();

            }

        });

        threadOne.start();

    }
}
