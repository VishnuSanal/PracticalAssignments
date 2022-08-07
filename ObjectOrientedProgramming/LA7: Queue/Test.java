public class Test {

    public static void main(String[] args) {

        QueueFactory queueFactory = new QueueFactory();

        queueFactory.enqueue("A");
        queueFactory.display();

        queueFactory.dequeue();
        queueFactory.display();

        queueFactory.enqueue("B");
        queueFactory.display();

        queueFactory.enqueue("C");
        queueFactory.display();

        queueFactory.dequeue();
        queueFactory.display();

        queueFactory.enqueue("D");
        queueFactory.display();

    }

}
