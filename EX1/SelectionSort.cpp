#include <iostream>
using namespace std;
void selectionSort(int A[], int n) {
    for (int i = 0; i <= n - 2; i++) {
        int min = i;
        for (int j = i + 1; j <= n-1; j++) {
            if (A[j] < A[min]) {
                min = j;
            }
        }
        int temp = A[i];
        A[i] = A[min];
        A[min] = temp;
        cout << "Pass " << i + 1 << ": ";
        for (int k = 0; k < n; k++) {
            if (k <= i) {
                cout << "[" << A[k] << "] ";
            } else {
                cout << A[k] << " ";
            }
        }
        cout << endl;
    }
}
int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    
    int A[100];
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    selectionSort(A, n);
    return 0;
}
