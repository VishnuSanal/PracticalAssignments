public class BinarySearch {

    public static int binarySearch(int[] arr, int val) {
        int start = 0, end = arr.length - 1;

        while (start <= end) {

            int i = (start + end) / 2;

            if (val == arr[i])
                return i;
            else if (val > arr[i])
                start = i + 1;
            else
                end = i - 1;

        }

        return -1;
    }

}
