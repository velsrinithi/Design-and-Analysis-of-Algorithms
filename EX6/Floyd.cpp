#include <iostream>
using namespace std;

#define INF -1

void printMatrix(int D[10][10], int n, int step) {
    cout << "\nD(" << step << "):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << D[i][j] << "\t";   
        }
        cout << endl;
    }
}

int main() {
    int n, edges;
    int D[10][10];

    cout << "Enter number of vertices: ";
    cin >> n;

    // Initialize matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                D[i][j] = 0;
            else
                D[i][j] = INF;
        }
    }

    cout << "Enter number of edges: ";
    cin >> edges;

    for (int i = 0; i < edges; i++) {
        int u, v, cost;
        cout << "Enter start vertex: ";
        cin >> u;
        cout << "Enter end vertex: ";
        cin >> v;
        cout << "Enter cost: ";
        cin >> cost;

        if (u >= 0 && u < n && v >= 0 && v < n)
            D[u][v] = cost;
    }

    // Initial matrix
    printMatrix(D, n, 0);

    // Floyd's Algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (D[i][k] != INF && D[k][j] != INF) {
                    int through_k = D[i][k] + D[k][j];

                    if (D[i][j] == INF || through_k < D[i][j]) {
                        D[i][j] = through_k;
                    }
                }
            }
        }

        // Print after each iteration
        printMatrix(D, n, k + 1);
    }

    return 0;
}
