public class QuickSort {

    public static String[] quickSort(String[] arr, int low, int high) {

        if (low < high) {

            int p = partition(arr, low, high);

            quickSort(arr, low, p - 1);

            quickSort(arr, p + 1, high);

        }

        return arr;
    }

    private static int partition(String[] arr, int low, int high) {

        String pivot = arr[high];

        int i = low - 1;

        for (int j = low; j < high; j++)
            if (arr[j].compareToIgnoreCase(pivot) < 0)
                swap(arr, ++i, j);

        swap(arr, i + 1, high);

        return i + 1;
    }

    private static void swap(String[] arr, int i, int j) {
        String temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

}
