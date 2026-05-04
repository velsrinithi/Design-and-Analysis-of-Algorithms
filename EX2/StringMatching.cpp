#include <iostream>
#include <string>
using namespace std;

void bruteForce(string T, string P) {

    int n = T.length();
    int m = P.length();
    int comparisons = 0;
    int alignments = 0;
    int found = -1;
    cout << "Text:    " << T << endl;
    for (int i = 0; i <= n - m; i++) {
        alignments++;
        // Print pattern movement
        cout << "Pattern: ";
        for (int s = 0; s < i; s++)
            cout << " ";
        cout << P << endl;
        int j = 0;
        while (j < m && P[j] == T[i + j]) {
            comparisons++;
            j++;
        }
        if (j < m) comparisons++;
        if (j == m) {
            found = i;
            break;
        }
    }
    cout << "\nComparisons: " << comparisons << endl;
    if (found != -1) {
        cout << "Found at index: " << found << endl;
        cout << "Alignments: " << found + 1 << endl;
    } else {
        cout << "Not found\n";
        cout << "Alignments: " << n - m + 1 << endl;
    }
}
int main() {
    string T, P;
    cout << "Enter Text: ";
    getline(cin, T);  
    cout << "Enter Pattern: ";
    getline(cin, P);  
    bruteForce(T, P);
    return 0;
}

