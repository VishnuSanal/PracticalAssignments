public class Video {

    private String name;
    private boolean checkout;
    private int rating;

    public Video(String name) {
        this.name = name;
    }

    public void doCheckout(String name) {
        checkout = true; //TODO: Why the name parameter?!
    }

    public void doReturn(String name) {
        checkout = false; //TODO: Why the name parameter?!
    }

    public void receiveRating(int rating) {
        this.rating = rating; //TODO: Why receive not get? Why not use the getter!!
    }

    public boolean getCheckout() {
        return checkout;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public boolean isCheckout() {
        return checkout;
    }

    public void setCheckout(boolean checkout) {
        this.checkout = checkout;
    }

    public int getRating() {
        return rating;
    }

    public void setRating(int rating) {
        this.rating = rating;
    }
}