public class Test {

    public static void main(String[] args) {

        DoublyLinkedList list = new DoublyLinkedList();

        list.insert(0);
        list.insert(1);
        list.insert(2);
        list.insert(3);
        list.insert(4);
        list.insert(5);

        list.display();

        list.delete(0);
        list.display();

        list.delete(3);
        list.display();

        list.delete(5);
        list.display();

        list.delete(9);
        list.display();

        list.insert(-1);
        list.insert(-2);
        list.insert(-3);

        list.display();

    }

}
