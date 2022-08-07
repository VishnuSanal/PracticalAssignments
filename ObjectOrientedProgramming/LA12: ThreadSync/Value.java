public class Value {

    private int value;

    public Value() {
    }

    public Value(int i) {
        this.value = i;
    }

    public int getValue() {
        return value;
    }

    public void setValue(int value) {
        this.value = value;
    }

    public synchronized void incrementValue() {

        System.out.println("Value#incrementValue -> Before: " + getValue());
        setValue(getValue() + 1);
        System.out.println("Value#incrementValue -> After: " + getValue());

    }
}
