#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& vis, int curr, int& candidate, int& dist) {
        vis[node] = true;
        if (dist<curr) {
            candidate = node;
            dist = curr;
        }
        for (auto j: adj[node]) {
            if (!vis[j]) {
                dfs(j, adj, vis, curr+1, candidate, dist);
            }
        } 
    }
    int diameter(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V);
        for (auto i: edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        int candidate=0, dist=0;
        vector<bool> vis(V, false);
        dfs(0, adj, vis, 0, candidate, dist);
        for (int i=0; i<V; i++) vis[i] = false;
        dfs(candidate, adj, vis, 0, candidate, dist);
        return dist;
    }
};
