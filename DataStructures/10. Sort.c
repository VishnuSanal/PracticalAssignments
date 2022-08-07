#include <stdio.h>

int *bubbleSort(int[], int);
int *insertionSort(int[], int);
int *selectionSort(int[], int);

int *quickSort(int[], int, int);
int quickSortPartition(int[], int, int);

int *mergeSort(int[], int, int);
void mergeSortMerge(int[], int, int, int);

int *heapSort(int[], int);
void heapSortHeapify(int[], int, int);

void swap(int *, int *);
void printArray(char s[], int *arr, int n);

int main() {

  // int arr[] = {-2, 45, 0, 11, -9};
  // int n = sizeof(arr) / sizeof(arr[0]);

  int n;

  printf("Enter the size of the array: ");
  scanf("%d", &n);

  int arr[n];

  for (int i = 0; i < n; i++) {
    printf("Enter the %dth element: ", i);
    scanf("%d", &arr[i]);
  }

  printArray("Bubble sort:", bubbleSort(arr, n), n);
  printArray("Insertion sort:", insertionSort(arr, n), n);
  printArray("Selection sort:", selectionSort(arr, n), n);
  printArray("Quick sort:", quickSort(arr, 0, n - 1), n);
  printArray("Merge sort:", mergeSort(arr, 0, n - 1), n);
  printArray("Heap sort:", heapSort(arr, n), n);

  printf("\n");

  return 0;
}

int *bubbleSort(int arr[], int n) {

  for (int i = 0; i < n - 1; i++)
    for (int j = 0; j < n - i - 1; j++)
      if (arr[j] > arr[j + 1])
        swap(&arr[j], &arr[j + 1]);

  return arr;
}

int *insertionSort(int arr[], int n) {

  for (int i = 1; i < n; i++) {

    int key = arr[i], j = i - 1;

    while (arr[j] > key && j >= 0)
      arr[j + 1] = arr[j--];

    arr[j + 1] = key;
  }

  return arr;
}

int *selectionSort(int arr[], int n) {

  for (int i = 0; i < n - 1; i++) {

    int min = i;

    for (int j = i + 1; j < n; j++)
      if (arr[j] < arr[min])
        min = j;

    swap(&arr[i], &arr[min]);
  }

  return arr;
}

int *quickSort(int arr[], int low, int high) {
  if (low < high) {

    int p = quickSortPartition(arr, low, high);

    quickSort(arr, low, p - 1);

    quickSort(arr, p + 1, high);
  }

  return arr;
}

int quickSortPartition(int arr[], int left, int right) {

  int pivot = arr[left], l = left + 1, r = right;

  while (l < r) {

    while (l < right && arr[l] < pivot)
      l++;

    while (r > left && arr[r] >= pivot)
      r--;

    if (l < r)
      swap(&arr[l], &arr[r]);
  }

  arr[left] = arr[r];
  arr[r] = pivot;

  return r;
}

int *mergeSort(int arr[], int l, int r) {
  if (l < r) {

    int m = (l + r) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    mergeSortMerge(arr, l, m, r);
  }
  return arr;
}

void mergeSortMerge(int arr[], int p, int q, int r) {

  int n1 = q - p + 1;
  int n2 = r - q;

  int L[n1], M[n2];

  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];

  for (int i = 0; i < n2; i++)
    M[i] = arr[q + i + 1];

  int i = 0, j = 0, k = p;

  while (i < n1 && j < n2)
    if (L[i] <= M[j])
      arr[k++] = L[i++];
    else
      arr[k++] = M[j++];

  while (i < n1)
    arr[k++] = L[i++];

  while (j < n2)
    arr[k++] = M[j++];
}

int *heapSort(int arr[], int n) {

  for (int i = n / 2 - 1; i >= 0; i--)
    heapSortHeapify(arr, n, i);

  for (int i = n - 1; i >= 0; i--) {
    swap(&arr[0], &arr[i]);

    heapSortHeapify(arr, i, 0);
  }

  return arr;
}

void heapSortHeapify(int arr[], int n, int i) {

  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < n && arr[left] > arr[largest])
    largest = left;

  if (right < n && arr[right] > arr[largest])
    largest = right;

  if (largest != i) {
    swap(&arr[i], &arr[largest]);
    heapSortHeapify(arr, n, largest);
  }
}

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void printArray(char s[], int *arr, int n) {

  printf("\n%s\n", s);

  for (int i = 0; i < n; i++)
    printf("%d\t", arr[i]);
}
