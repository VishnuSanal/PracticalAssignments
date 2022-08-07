public class DoublyLinkedList {

    private Node HEAD = null;

    public void insert(int val) {

        Node newNode = new Node(val, null, null);

        if (HEAD == null) {

            HEAD = newNode;
            newNode.setPrev(HEAD);
            return;

        }

        Node ptr = HEAD;

        while (ptr.getNext() != null)
            ptr = ptr.getNext();

        ptr.setNext(newNode);
        newNode.setPrev(ptr);

    }

    public void delete(int key) {

        if (HEAD == null) {
            System.out.println("List empty");
            return;
        }

        Node ptr = HEAD;

        while (ptr.getData() != key) {

            if (ptr.getNext() == null) {
                System.out.println("Element not found");
                return;
            }

            ptr = ptr.getNext();
        }

        if (ptr == HEAD) {
            HEAD = ptr.getNext();
            ptr.setPrev(HEAD);
            return;
        }

        ptr.getPrev().setNext(ptr.getNext());

        if (ptr.getNext() == null)
            return;

        ptr.getNext().setPrev(ptr.getPrev());

    }

    public void display() {

        if (HEAD == null) {
            System.out.println("List is empty");
            return;
        }

        Node ptr = HEAD;

        while (ptr != null) {
            System.out.print(ptr.getData() + "\t");
            ptr = ptr.getNext();
        }

        System.out.println();

    }

}
