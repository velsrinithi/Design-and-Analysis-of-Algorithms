#include <iostream>
#include <cmath>
using namespace std;

int x[20];
int solutionCount = 0;

// Function to print the solution
void printMatrix(int n) {
    solutionCount++;
    cout << "Solution " << solutionCount << ":\n";

    for (int row = 1; row <= n; row++) {
        for (int col = 1; col <= n; col++) {
            if (x[row] == col)
                cout << " Q ";
            else
                cout << " . ";
        }
        cout << endl;
    }
    cout << endl;
}

// Function to check if queen can be placed
bool Place(int k, int i) {
    for (int j = 1; j < k; j++) {
        if (x[j] == i || abs(x[j] - i) == abs(j - k))
            return false;
    }
    return true;
}

// N-Queens using backtracking
void NQueens(int k, int n) {
    for (int i = 1; i <= n; i++) {
        if (Place(k, i)) {
            x[k] = i;

            if (k == n)
                printMatrix(n);
            else
                NQueens(k + 1, n);
        }
    }
}

int main() {
    int n;

    cout << "Enter the number of queens (n): ";
    cin >> n;

    if (n > 0 && n < 20) {
        NQueens(1, n);

        if (solutionCount == 0)
            cout << "No solutions found.\n";
    } else {
        cout << "Please enter a valid number (1-19).\n";
    }

    return 0;
}
