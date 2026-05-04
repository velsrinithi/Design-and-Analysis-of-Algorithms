
#include <iostream>
#include <string>
using namespace std;

// Horspool Algorithm Function
void horspool(const string &text, const string &pattern) {

    int n = text.size(), m = pattern.size();  
    // n → length of text, m → length of pattern

    int shift[27];  
    // shift table (A–Z → 0–25, '_' → 26)

    // Step 1: Initialize all shift values to pattern length
    for (int i = 0; i < 27; i++) 
        shift[i] = m;

    //  Step 2: Update shift table using pattern
    for (int j = 0; j < m - 1; j++) {

        int idx;

        if (pattern[j] == '_')     // if underscore
            idx = 26;
        else
            idx = pattern[j] - 'A';   // convert char to index (A=0,...)

        shift[idx] = m - 1 - j;   // store shift value
    }

    // Step 3: Display shift table
    cout << "\n--- Shift Table ---\n";
    for (int i = 0; i < 26; i++) {
        cout << char('A' + i) << ":" << shift[i] << " ";
    }
    cout << "_:" << shift[26] << endl;

    // Step 4: Searching process
    int i = m - 1;      // start from end of pattern
    int comps = 0;      // number of comparisons
    int aligns = 0;     // number of alignments

    while (i < n) {

        aligns++;       // new alignment attempt
        int k = 0;

        //  Compare from right to left
        while (k < m && pattern[m - 1 - k] == text[i - k]) {
            comps++;    // count successful comparison
            k++;
        }

        // If full match found
        if (k == m) {
            cout << "\nPattern found at index: " << i - m + 1
                 << "\nTotal Comparisons: " << comps
                 << "\nTotal Alignments: " << aligns << endl;

            /*
            Example Output:
            Pattern found at index: 16
            Total Comparisons: 10
            Total Alignments: 9
            */

            return;     // stop execution
        }

        comps++;   // count mismatch comparison

        int idx;

        // find index of mismatched character in text
        if (text[i] == '_')
            idx = 26;
        else
            idx = text[i] - 'A';

        i += shift[idx];   // shift pattern based on table
    }

    // If pattern not found
    cout << "\nPattern not found"
         << "\nTotal Comparisons: " << comps
         << "\nTotal Alignments: " << aligns << endl;
}


// Main Function
int main() {

    string text, pattern;

    // Input text
    cout << "Enter Text (CAPITALS and _ only): ";
    cin >> text;

    // Input pattern
    cout << "Enter Pattern (CAPITALS and _ only): ";
    cin >> pattern;

    // Call Horspool function
    horspool(text, pattern);
}
