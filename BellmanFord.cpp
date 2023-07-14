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