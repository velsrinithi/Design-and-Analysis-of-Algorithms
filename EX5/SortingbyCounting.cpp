#include <iostream>
using namespace std;

// Function for Comparison Counting Sort
void comparisonCountSort(int A[], int n)
{
    int Count[n], S[n];

    // Display original array
    cout << "\nArray A[0.." << n - 1 << "]:\n";
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << "\n";

    // Initialize Count array to 0
    for (int i = 0; i < n; i++)
        Count[i] = 0;

 

    // Display initial Count array
    cout << "\nInitially Count[]:\n";
    for (int i = 0; i < n; i++)
        cout << Count[i] << " ";
    cout << "\n";

    // Core logic: count smaller elements
    for (int i = 0; i <= n - 2; i++)
    {
        for (int j = i + 1; j <= n-1; j++)
        {
            if (A[i] < A[j])
                Count[j]++;   // increment count of larger element
            else
                Count[i]++;   // increment count of larger element
        }

        // Show Count after each pass
        cout << "\nAfter pass i = " << i << ":\n";
        cout << "Count[]: ";
        for (int k = 0; k < n; k++)
            cout << Count[k] << " ";
        cout << "\n";
    }

    // Final Count array
    cout << "\nFinal Count[]:\n";
    for (int i = 0; i < n; i++)
        cout << Count[i] << " ";
    cout << "\n";

    // Place elements in sorted positions
    for (int i = 0; i < n; i++)
        S[Count[i]] = A[i];

    // Display sorted array
    cout << "\nArray S[0.." << n - 1 << "]:\n";
    for (int i = 0; i < n; i++)
        cout << S[i] << " ";
    cout << "\n";
}


// Main Function
int main()
{
    int n;

    // Read number of elements
    cout << "Enter number of elements: ";
    cin >> n;

    int A[n];

    // Read elements
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> A[i];

    // Call sorting function
    comparisonCountSort(A, n);

    return 0;
}
