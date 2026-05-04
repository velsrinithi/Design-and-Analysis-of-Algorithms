#include <iostream>
using namespace std;

// Function to print array
void printArray(int A[], int n) {
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;
}

// Hoare Partition with iteration printing
int hoarePartition(int A[], int l, int r, int n) {

    int pivot = A[l];
    int i = l - 1;
    int j = r + 1;

    cout << "\nPivot = " << pivot << endl;

    while (true) {

        do {
            i++;
        } while (A[i] < pivot);

        do {
            j--;
        } while (A[j] > pivot);

        if (i >= j) {
            cout << "Partition position: " << j << endl;
            return j;
        }

        // swap and print
        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;

        cout << "Swap A[" << i << "] and A[" << j << "] → ";
        printArray(A, n);
    }
}

// Quicksort
void quickSort(int A[], int l, int r, int n) {

    if (l < r) {

        int s = hoarePartition(A, l, r, n);

        quickSort(A, l, s, n);
        quickSort(A, s + 1, r, n);
    }
}

int main() {

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int A[100];

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> A[i];

    cout << "\nInitial Array:\n";
    printArray(A, n);

    quickSort(A, 0, n - 1, n);

    cout << "\nSorted Array:\n";
    printArray(A, n);

    return 0;
}

