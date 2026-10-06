#include <stdio.h>

#define SIZE 50

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

/* insert into a max heap: place at the end, then heapify-up */
void insertHeap(int heap[], int *n, int key)
{
    int i = *n;
    heap[i] = key;
    (*n)++;
    while (i > 0 && heap[(i - 1) / 2] < heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void heapify(int arr[], int n, int i)
{
    int largest = i, l = 2 * i + 1, r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    int i;
    for (i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

int main()
{
    int n, count = 0, i, x;
    int heap[SIZE];

    printf("Enter number of elements: ");
    scanf("%d", &n);
    if (n < 1 || n > SIZE) {
        printf("Number of elements must be between 1 and %d\n", SIZE);
        return 1;
    }




    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        insertHeap(heap, &count, x);
    }

    printf("Max Heap (array form): ");
    for (i = 0; i < count; i++)
        printf("%d ", heap[i]);
    printf("\n");

    heapSort(heap, count);

    printf("Sorted array (Ascending using Heap): ");
    for (i = 0; i < count; i++)
        printf("%d ", heap[i]);
    printf("\n");
    return 0;
}
