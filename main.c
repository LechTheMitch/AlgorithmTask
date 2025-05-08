#include <stdio.h>
#define MAX 100

void merge(int arr[], int l, int m, int r);
void mergeSort(int arr[], int l, int r);
int hasTriplet(int sortedArr[], int arrSize);
void heapify(int arr[], int n, int i);
void heapSort(int arr[], int n);
int hasTripletHeap(int sortedArr[], int arrSize);

int main(void) {
    int arr[MAX], noOfInputs=0, choice=0;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &noOfInputs);
    printf("Enter the elements of the array: ");
    for (int i = 0; i < noOfInputs; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Choose the sorting algorithms to use:\n");
    printf("\t1. Merge Sort\n");
    printf("\t2. Heap Sort\n");
    scanf("%d", &choice);
    if (choice==1) {
        hasTriplet(arr, noOfInputs) ? printf("This Array is Triangular\n") : printf("This Array isn't Triangular\n");
    } else if (choice==2) {
        hasTripletHeap(arr, noOfInputs) ? printf("This Array is Triangular\n") : printf("This Array isn't Triangular\n");
    } else {
        printf("Invalid choice.\n");
    }
    return 0;
}

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest]) {
        largest = l;
    }
    if (r < n && arr[r] > arr[largest]) {
        largest = r;
    }
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}
void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}
int hasTriplet(int sortedArr[], int arrSize)
{
    if (arrSize < 3) {
        return 0;
    }
    mergeSort(sortedArr, 0, arrSize - 1);
    for (int i = 0; i < arrSize - 2; i++) {
        if (sortedArr[i] + sortedArr[i + 1] > sortedArr[i + 2]) {
            return 1;
            }
        }
    return 0;
}
int hasTripletHeap(int sortedArr[], int arrSize) {
    if (arrSize < 3) {
        return 0;
    }
    heapSort(sortedArr, arrSize);
    for (int i = 0; i < arrSize - 2; i++) {
        if (sortedArr[i] + sortedArr[i + 1] > sortedArr[i + 2]) {
            return 1;
        }
    }
    return 0;
}
