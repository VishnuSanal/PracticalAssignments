public interface Queue {
    public int size(); //Returns number of objects in queue
    public boolean isEmpty(); //Returns true if queue is empty
    //Adds an item to the tail of the queue
    public void enqueue(Object o);
    //Removes and returns the item from the head of the queue
    public Object dequeue();
}