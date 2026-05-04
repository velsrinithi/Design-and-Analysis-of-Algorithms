#include <iostream>
#include <algorithm>
using namespace std;

struct Item {
    int weight, profit;
    float ratio;
};

// Sort items by profit/weight ratio
bool compare(Item a, Item b) {
    return a.ratio > b.ratio;
}

// Calculate upper bound
float bound(int n, int W, int profit, int weight, Item items[], int level) {
    float result = profit;

    for (int i = level; i < n; i++) {
        if (weight + items[i].weight <= W) {
            weight += items[i].weight;
            result += items[i].profit;
        } else {
            result += (W - weight) * items[i].ratio;
            break;
        }
    }

    return result;
}

// Branch and Bound Knapsack
void knapsack(int n, int W, Item items[]) {
    sort(items, items + n, compare);

    int maxProfit = 0;

    // simple queue using array
    struct Node {
        int level, profit, weight;
        float bound;
    };

    Node Q[100];
    int front = 0, rear = 0;

    Node u, v;

    // Start node
    v.level = 0;
    v.profit = 0;
    v.weight = 0;
    v.bound = bound(n, W, 0, 0, items, 0);

    Q[rear++] = v;

    while (front < rear) {
        v = Q[front++];

        if (v.level == n || v.bound <= maxProfit)
            continue;

        // Include item
        u.level = v.level + 1;
        u.weight = v.weight + items[v.level].weight;
        u.profit = v.profit + items[v.level].profit;

        if (u.weight <= W && u.profit > maxProfit)
            maxProfit = u.profit;

        u.bound = bound(n, W, u.profit, u.weight, items, u.level);

        if (u.bound > maxProfit)
            Q[rear++] = u;

        // Exclude item
        u.weight = v.weight;
        u.profit = v.profit;
        u.bound = bound(n, W, u.profit, u.weight, items, u.level);

        if (u.bound > maxProfit)
            Q[rear++] = u;
    }

    cout << "\nMaximum Profit = " << maxProfit << endl;
}

int main() {
    int n, W;

    cout << "Enter number of items: ";
    cin >> n;

    Item items[20];

    cout << "Enter weight and profit:\n";
    for (int i = 0; i < n; i++) {
        cin >> items[i].weight >> items[i].profit;
        items[i].ratio = (float)items[i].profit / items[i].weight;
    }

    cout << "Enter capacity: ";
    cin >> W;

    knapsack(n, W, items);

    return 0;
}
