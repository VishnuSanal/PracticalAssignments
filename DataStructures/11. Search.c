#include <stdio.h>

int linearSearch(int[], int, int);
int binarySearch(int[], int, int);

int *bubbleSort(int[], int);

void swap(int *, int *);
void printArray(char[], int *, int);

int main() {

  // int arr[] = {-2, 45, 0, 11, -9};
  // int n = sizeof(arr) / sizeof(arr[0]);
  // int key = 45;

  int n, key;

  printf("Enter the size of the array: ");
  scanf("%d", &n);

  int arr[n];

  for (int i = 0; i < n; i++) {
    printf("Enter the %dth element: ", i);
    scanf("%d", &arr[i]);
  }

  printf("Enter the value to be searched for: ");
  scanf("%d", &key);

  printArray("Original array:", arr, n);

  printf("\n");

  printf("\nLinear Search: Index: %d\n", linearSearch(arr, n, key));

  printf("\nSorting the array to perform binary search...\n");

  *arr = *bubbleSort(arr, n);

  printArray("Sorted array:", arr, n);

  printf("\n\nBinary Search: Index: %d", binarySearch(arr, n, key));

  printf("\n\n");

  return 0;
}

int *bubbleSort(int arr[], int n) {

  for (int i = 0; i < n - 1; i++)
    for (int j = 0; j < n - i - 1; j++)
      if (arr[j] > arr[j + 1])
        swap(&arr[j], &arr[j + 1]);

  return arr;
}

int linearSearch(int arr[], int n, int key) {

  for (int i = 0; i < n - 1; i++)
    if (arr[i] == key)
      return i;

  return -1;
}

int binarySearch(int arr[], int n, int key) {

  int left = 0, right = n - 1;

  while (left <= right) {

    int i = (left + right) / 2;

    if (arr[i] == key)
      return i;
    else if (key > arr[i])
      left = i + 1;
    else
      right = i - 1;
  }

  return -1;
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

