#include <iostream>
using namespace std;

// Function to build heap using bottom-up approach
void heapBottomUp(int h[], int n) {
    int k, v, j;
    bool isHeap;

    for (int i = n / 2; i >= 1; i--) {
        k = i;
        v = h[k];
        isHeap = false;

        while (!isHeap && 2 * k <= n) {
            j = 2 * k; // left child

            // choose larger child
            if (j < n && h[j] < h[j + 1]) {
                j = j + 1;
            }

            // check heap condition
            if (v >= h[j]) {
                isHeap = true;
            } else {
                h[k] = h[j];
                k = j;
            }
        }

        h[k] = v;
    }
}

// Heap Sort function
void heapSort(int h[], int n) {
    int temp;

    // Build heap
    heapBottomUp(h, n);

    // Extract elements one by one
    for (int i = n; i >= 2; i--) {
        // swap root with last element
        temp = h[1];
        h[1] = h[i];
        h[i] = temp;

        // rebuild heap for remaining elements
        heapBottomUp(h, i - 1);
    }
}

int main() {
    int h[100], n;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }

    heapSort(h, n);

    cout << "Sorted Array:\n";
    for (int i = 1; i <= n; i++) {
        cout << h[i] << " ";
    }

    return 0;
}
