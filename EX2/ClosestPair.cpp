#include <iostream>
#include <cmath>
#include <iomanip>   // for setprecision
using namespace std;
// Function to find closest pair
void closestPair(int x[], int y[], int n) {
    double minDist = 99999;
    cout << fixed << setprecision(2);  // round to 2 decimal places
    cout << "\nDistances between pairs:\n";
    // Check all pairs
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            // Distance formula
            double d = sqrt((x[j] - x[i]) * (x[j] - x[i]) +
                            (y[j] - y[i]) * (y[j] - y[i]));
                            // Print each pair distance
            cout << "Between (" << x[i] << "," << y[i] << ") and ("
                 << x[j] << "," << y[j] << ") = " << d << endl;
                 // Update minimum distance
            if (d < minDist) {
                minDist = d;
            }
        }
    }
    cout << "\nClosest distance: " << minDist << endl;
}
int main() {
    int n;
    cout << "Enter number of points: ";
    cin >> n;
    int x[100], y[100];
    // Input points
    cout << "Enter points (x y):\n";
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    // Function call
    closestPair(x, y, n);
    return 0;
}
