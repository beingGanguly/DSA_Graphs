#include<iostream>
#include<vector>
using namespace std;

int TSP(vector<vector<int>>&graph, int start, int mask, vector<vector<int>>&dp){
    int n = graph.size();

    if(mask == (1<<n)-1){
        return graph[start][0];
    }

    if(dp[start][mask] != -1){
        return dp[start][mask];
    }

    int minCost = INT_FAST16_MAX;
    for(int i=0;i<n;i++){
        if(((mask>>i)&1)==0){
            int newMask = mask | (1<<i);
            int cost = graph[start][i] + TSP(graph, i, newMask, dp);

            minCost = min(minCost,cost);
        }
    }
    dp[start][mask] = minCost;

    return minCost;
}

int main() {
    // Sample graph with distances between cities.
    vector<vector<int>> graph = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    int n = graph.size();

    // Initialize the dp array with -1 (unvisited).
    vector<vector<int>> dp(n, vector<int>(1 << n, -1));

    // Starting city (usually 0 for the Traveling Salesman Problem).
    int start = 0;

    // Initially, the mask is 1, representing that the starting city is visited.
    int mask = 1;

    // Call the TSP function to find the minimum cost of the traveling salesman tour.
    int minCost = TSP(graph, start, mask, dp);

    cout << "Minimum cost of the TSP tour: " << minCost << endl;

    return 0;
}