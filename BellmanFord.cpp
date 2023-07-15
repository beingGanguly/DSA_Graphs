#include<iostream>
#include<vector>
using namespace std;

vector<int>bellman_ford(int V, vector<vector<int>>&edges, int S){
    vector<int>dist(V,1e9); // Assigning infinite distance from source to all the nodes

    for(int i=0;i<V-1;i++){
        dist[S] = 0; // Keeping the distance of source as 0
        for(auto it: edges){
            int u  = it[0];
            int v  = it[1];
            int wt = it[2];
            if(dist[u] != 1e9 && dist[u]+wt < dist[v]){
                dist[v] = dist[u] + wt;
            }
        }
    }

    // N th relaxation is to be checked for negative cycle
    for(auto it: edges){
        int u  = it[0];
        int v  = it[1];
        int wt = it[2];
        if(dist[u] != 1e9 && dist[u]+wt < dist[v]){
            dist[v] = dist[u] + wt;
        }
    }
    return dist;
}

int main() {
    int V = 5; // Number of vertices
    vector<vector<int>> edges;

    // Add edges to the list
    edges.push_back({0, 1, 2});
    edges.push_back({0, 2, 4});
    edges.push_back({1, 2, 1});
    edges.push_back({1, 3, 7});
    edges.push_back({2, 4, 3});
    edges.push_back({3, 4, 2});
    edges.push_back({3, 5, 5});
    edges.push_back({4, 5, 1});

    int source = 0; // Source vertex

    // Call Bellman Ford algorithm to calculate shortest distances
    vector<int> shortestDistances = bellman_ford(V, edges, source);

    // Print the shortest distances from the source vertex to all other vertices
    cout << "Shortest distances from vertex " << source << ":\n";
    for (int i = 0; i < V; i++) {
        cout << "Vertex " << i << ": " << shortestDistances[i] << "\n";
    }

    return 0;
}