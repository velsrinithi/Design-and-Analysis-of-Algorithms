#include <iostream>
using namespace std;

void bubbleSort(int A[], int n) {

    cout<<"initial:";
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << "\n\n";

    for (int i = 0; i < n - 1; i++) {

        cout << "Pass " << i + 1 << ":\n";

        for (int j = 0; j < n - 1 - i; j++) {

            // show comparison
            for (int k = 0; k < n; k++) {
                if (k == j)
                    cout << A[k] << " ↔ ";
                else
                    cout << A[k] << " ";
            }

            // swap if needed
            if (A[j] > A[j + 1]) {
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
                cout << " (swap)";
            } else {
                cout << " (ns)";
            }

            cout << endl;
        }

        // show result after pass
        cout << "Result: ";
        for (int i = 0; i < n; i++)
            cout << A[i] << " ";
        cout << "\n\n";
    }
}

int main() {
    int n, A[100];

    cout << "Enter n: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> A[i];

    bubbleSort(A, n);

    return 0;
}
