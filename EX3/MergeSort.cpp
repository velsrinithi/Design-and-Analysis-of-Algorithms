#include <iostream>
using namespace std;

// Merge function
void merge(int A[], int l, int mid, int r) {

    int i = l;        // left subarray start
    int j = mid + 1;  // right subarray start
    int k = l;        // temp array index

    int B[100];       // temporary array

    // Merge both subarrays
    while (i <= mid && j <= r) {
        if (A[i] <= A[j]) {
            B[k] = A[i];
            i++;
        } else {
            B[k] = A[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of left subarray
    while (i <= mid) {
        B[k] = A[i];
        i++; k++;
    }

    // Copy remaining elements of right subarray
    while (j <= r) {
        B[k] = A[j];
        j++; k++;
    }

    // Copy back to original array
    for (int p = l; p <= r; p++) {
        A[p] = B[p];
    }
}

// MergeSort function
void mergeSort(int A[], int l, int r) {

    if (l < r) {

        int mid = (l + r) / 2;

        // Divide
        mergeSort(A, l, mid);
        mergeSort(A, mid + 1, r);

        // Merge
        merge(A, l, mid, r);
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

    mergeSort(A, 0, n - 1);

    cout << "Sorted array:\n";
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";

    return 0;
}
