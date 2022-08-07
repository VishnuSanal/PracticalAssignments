public class VideoStore {

    private static final Video[] store = new Video[100]; // TODO: What should be the size of this array? Better using an <code>ArrayList</code>?
    private static int length = 0; // TODO: Can't find any other ways to do this other than of course to loop through the array to find the end!!

    public static void addVideo(String name) {
        store[length++] = new Video(name);
        System.out.println("Video “" + name + "” added successfully.");
    }

    public static void doCheckout(String name) {
        for (Video video : store) {
            if (name.equals(video.getName())) { //TODO: Not doing .toLower() because it is the primary key
                video.doCheckout(name); //TODO: This name is redundant, as far as I can decipher.
                System.out.println("Video “" + name + "” checked out successfully.");
                return;
            }
        }
    }

    public static void doReturn(String name) {
        for (Video video : store) {
            if (name.equals(video.getName())) { //TODO: Not doing .toLower() because it is the primary key
                video.doReturn(name); //TODO: This name is redundant, as far as I can decipher.
                System.out.println("Video “" + name + "” returned successfully.");
                return;
            }
        }
    }

    public static void receiveRating(String name, int rating) {
        for (Video video : store) {
            if (name.equals(video.getName())) { //TODO: Not doing .toLower() because it is the primary key
                video.receiveRating(rating);
                System.out.println("Rating “9” has been mapped to the Video “" + name + "”.");
                return;
            }
        }
    }

    public static void listInventory() {

        System.out.println(
                "--------------------------------------------------------\n" +
                        "Video Name | Checkout Status | Rating\n"
        );

        if (store != null && length > 0)
            for (int i = 0; i < length; i++)
                printDetails(store[i]);

        System.out.println(
                "--------------------------------------------------------"
        );
    }

    private static void printDetails(Video video) {
        System.out.println(
                video.getName() + " | " + video.getCheckout() + " | " + video.getRating() + " | "
        );
    }

}
