#include<iostream>
#include<vector>
using namespace std;

class KosarajuAlgorithm {
private:
    void dfs(int node,vector<vector<int>>&adj, vector<int>&vis, vector<int>&finishOrder){
        vis[node] = 1;
        for(int it: adj[node]){
            if(!vis[it]){
                dfs(it,adj,vis,finishOrder);
            }
        }
        finishOrder.push_back(node);
    }

    void dfs2(int node,vector<vector<int>>&adj, vector<int>&vis){
        vis[node] = 1;
        for(int it: adj[node]){
            if(!vis[it]){
                dfs2(it,adj,vis);
            }
        }
    }

public:
    int kosaraju(int V, vector<vector<int>>&adj){
        vector<int>vis(V,0);
        vector<int>finishOrder;

        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,adj,vis,finishOrder);
            }
        }

        //Creating the Transpose graph (adjT)
        vector<vector<int>>adjT(V);
        for(int i=0;i<V;i++){
            vis[i]=0;
            for(int it:adj[i]){
                adjT[it].push_back(i);
            }
        }

        //Last dfs using the finish order
        int scc = 0;
        for(int i=V-1;i>=0;i--){
            int node = finishOrder[i];
            if(!vis[node]){
                scc++;
                dfs2(node,adjT,vis);
            }
        }
        return scc;
    }
};

int main() {
    KosarajuAlgorithm algo;

    int V = 6; // Number of vertices
    vector<vector<int>> adj(V);

    // Add edges to the adjacency list representation of the graph
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(0);
    adj[2].push_back(3);
    adj[3].push_back(4);
    adj[4].push_back(5);
    adj[5].push_back(3);

    int stronglyConnectedComponents = algo.kosaraju(V, adj);
    cout << "Number of Strongly Connected Components: " << stronglyConnectedComponents << endl;

    return 0;
}



