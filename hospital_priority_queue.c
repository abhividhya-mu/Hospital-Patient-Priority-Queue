#include <stdio.h>

int heap[20], n = 0;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void display(int a[], int n)
{
    int i;

    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");
}

void insert(int value)
{
    int i, parent;

    n++;
    i = n - 1;
    heap[i] = value;

    while (i > 0)
    {
        parent = (i - 1) / 2;

        if (heap[parent] >= heap[i])
            break;

        swap(&heap[parent], &heap[i]);
        i = parent;
    }
}

void heapify(int a[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && a[left] > a[largest])
        largest = left;

    if (right < n && a[right] > a[largest])
        largest = right;

    if (largest != i)
    {
        swap(&a[i], &a[largest]);
        heapify(a, n, largest);
    }
}

void heapSort(int a[], int n)
{
    int i;

    for (i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);

    printf("Max Heap: ");
    display(a, n);

    for (i = n - 1; i > 0; i--)
    {
        swap(&a[0], &a[i]);
        heapify(a, i, 0);
    }
}

int partition(int a[], int low, int high)
{
    int pivot = a[high];
    int i = low - 1;
    int j;

    for (j = low; j < high; j++)
    {
        if (a[j] < pivot)
        {
            i++;
            swap(&a[i], &a[j]);
        }
    }

    swap(&a[i + 1], &a[high]);

    return i + 1;
}

void quickSort(int a[], int low, int high)
{
    int p;

    if (low < high)
    {
        p = partition(a, low, high);

        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
    }
}

int main()
{
    int data[] = {45, 72, 30, 90, 65, 50, 85};
    int heapData[7], quickData[7];
    int i;

    printf("MAX HEAP INSERTION\n");

    for (i = 0; i < 7; i++)
    {
        insert(data[i]);

        printf("After inserting %d: ", data[i]);
        display(heap, n);
    }

    printf("\nFinal Max Heap: ");
    display(heap, n);

    for (i = 0; i < 7; i++)
    {
        heapData[i] = data[i];
        quickData[i] = data[i];
    }

    printf("\nHEAP SORT\n");

    heapSort(heapData, 7);

    printf("Sorted array: ");
    display(heapData, 7);

    printf("\nQUICK SORT\n");

    quickSort(quickData, 0, 6);

    printf("Sorted array: ");
    display(quickData, 7);

    return 0;
}
