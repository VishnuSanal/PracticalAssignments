import java.util.ArrayList;

public final class QueueFactory implements Queue {

    private final ArrayList<Object> arrayList = new ArrayList<>();

    @Override
    public int size() {
        return arrayList.size();
    }

    @Override
    public boolean isEmpty() {
        return arrayList.isEmpty();
    }

    @Override
    public void enqueue(Object o) {
        arrayList.add(0, o);
    }

    @Override
    public Object dequeue() {
        if (!isEmpty())
            return arrayList.remove(arrayList.size() - 1);
        return null;
    }

}
