#include <stdio.h>

#define N 4 // Number of items
#define CAPACITY 10 // Capacity of the knapsack

// Structure to represent an item
struct Item {
    int weight;
    int profit;
};

// Function to find the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to solve the 0/1 Knapsack problem using Dynamic Programming
void knapsack(struct Item items[], int n, int capacity) {
    // Create a DP table
    int dp[n + 1][capacity + 1];

    // Initialize the DP table
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (items[i - 1].weight <= w)
                dp[i][w] = max(items[i - 1].profit + dp[i - 1][w - items[i - 1].weight], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    // Find the maximum profit
    int maxProfit = dp[n][capacity];
    printf("Maximum Profit: %d\n", maxProfit);

    // Find the items selected
    int remainingCapacity = capacity;
    printf("Items selected:\n");
    for (int i = n; i > 0 && maxProfit > 0; i--) {
        if (maxProfit != dp[i - 1][remainingCapacity]) {
            printf("Item %d (weight: %d, profit: %d)\n", i, items[i - 1].weight, items[i - 1].profit);
            maxProfit -= items[i - 1].profit;
            remainingCapacity -= items[i - 1].weight;
        }
    }
}

int main() {
    struct Item items[N] = {
        {2, 6},  // Item 1: weight = 2, profit = 6
        {3, 5},  // Item 2: weight = 3, profit = 5
        {4, 8},  // Item 3: weight = 4, profit = 8
        {5, 9}   // Item 4: weight = 5, profit = 9
    };

    knapsack(items, N, CAPACITY);

    return 0;
}
