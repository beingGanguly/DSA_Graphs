#include<iostream>
#include<vector>
#include <queue>
using namespace std;

vector<int>Dijkstra(int V, vector<vector<int>>adj[], int S){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int>dist(V);
    for(int i=0;i<V;i++){
        dist[i] = 1e9;
    }

    dist[S] = 0; // Source is kept at 0
    pq.push({0,S});

    while(!pq.empty()){
        int dis  = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for(auto it: adj[node]){
            int edgewt  = it[1];
            int adjNode = it[0];

            if(dis+edgewt<dist[adjNode]){
                dist[adjNode] = dis+edgewt;
                pq.push({dist[adjNode],adjNode});
            }
        }
    }
    return dist;
}

int main() {
    int V = 6; // Number of vertices
    vector<vector<int>> adj[V];

    // Add edges to the adjacency list representation of the graph
    adj[0].push_back({1, 2}); // Edge from vertex 0 to vertex 1 with weight 2
    adj[0].push_back({2, 4}); // Edge from vertex 0 to vertex 2 with weight 4
    adj[1].push_back({2, 1}); // Edge from vertex 1 to vertex 2 with weight 1
    adj[1].push_back({3, 7}); // Edge from vertex 1 to vertex 3 with weight 7
    adj[2].push_back({4, 3}); // Edge from vertex 2 to vertex 4 with weight 3
    adj[3].push_back({4, 2}); // Edge from vertex 3 to vertex 4 with weight 2
    adj[3].push_back({5, 5}); // Edge from vertex 3 to vertex 5 with weight 5
    adj[4].push_back({5, 1}); // Edge from vertex 4 to vertex 5 with weight 1

    int source = 0; // Source vertex

    // Call Dijkstra's algorithm to calculate shortest distances
    vector<int> shortestDistances = Dijkstra(V, adj, source);

    // Print the shortest distances from the source vertex to all other vertices
    cout << "Shortest distances from vertex " << source << ":\n";
    for (int i = 0; i < V; i++) {
        cout << "Vertex " << i << ": " << shortestDistances[i] << "\n";
    }

    return 0;
}