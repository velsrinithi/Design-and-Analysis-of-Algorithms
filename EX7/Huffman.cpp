#include <iostream>
#include <queue>
#include <vector>
#include <map>
using namespace std;

// Node structure
struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = NULL;
    }
};

// Comparator for priority queue (min heap)
struct compare {
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq;
    }
};

map<char, string> huffmanCode;

// Generate codes
void generateCodes(Node* root, string str) {
    if (!root) return;

    if (!root->left && !root->right) {
        huffmanCode[root->ch] = str;
    }

    generateCodes(root->left, str + "0");
    generateCodes(root->right, str + "1");
}

int main() {
    int n;
    cout << "Enter number of symbols: ";
    cin >> n;

    vector<char> chars(n);
    vector<int> freq(n);

    cout << "Enter symbols:\n";
    for (int i = 0; i < n; i++)
        cin >> chars[i];

    cout << "Enter frequencies:\n";
    int totalFreq = 0;
    for (int i = 0; i < n; i++) {
        cin >> freq[i];
        totalFreq += freq[i];
    }

    priority_queue<Node*, vector<Node*>, compare> pq;

    // Create leaf nodes
    for (int i = 0; i < n; i++) {
        pq.push(new Node(chars[i], freq[i]));
    }

    // Build Huffman Tree
    while (pq.size() > 1) {
        Node *left = pq.top(); pq.pop();
        Node *right = pq.top(); pq.pop();

        Node *newNode = new Node('\0', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;

        pq.push(newNode);
    }

    Node* root = pq.top();

    // Generate codes
    generateCodes(root, "");

    cout << "\nHuffman Codes:\n";
    for (auto pair : huffmanCode) {
        cout << pair.first << " : " << pair.second << endl;
    }

    // Calculate average bits
    double avgBits = 0;
    for (int i = 0; i < n; i++) {
        int codeLen = huffmanCode[chars[i]].length();
        avgBits += (double)freq[i] / totalFreq * codeLen;
    }

    cout << "\nAverage number of bits: " << avgBits << endl;

    // Assume fixed length coding
    int fixedBits = 0;
    while ((1 << fixedBits) < n) fixedBits++;

    double fixedAvg = fixedBits;

    cout << "Fixed length bits per symbol: " << fixedAvg << endl;

    // Compression ratio
    double compressionRatio = fixedAvg / avgBits;

    cout << "Compression Ratio: " << compressionRatio << endl;

    return 0;
}

