#include <stdio.h>
//descending Order

void minHeapify(int arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;
    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        int temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;
        minHeapify(arr, n, smallest);
    }
}

void buildMinHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        minHeapify(arr, n, i);
}

void heapSort(int arr[], int n) {
    buildMinHeap(arr, n);

    // One by one extract elements from heap
    for (int i = n - 1; i >= 0; i--) {
        // Move current root (smallest) to end
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // call heapify on the reduced heap
        minHeapify(arr, i, 0);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {10, 5, 20, 2, 8, 15, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, n);

    printf("Sorted array (Ascending order): ");
    printArray(arr, n);
    return 0;
}
