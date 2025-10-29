#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        // code here
        int n=grid.size(), m=grid[0].size();
        queue<pair<int, int>> q;
        vector<pair<int, int>> dirs = {{0,1},{1,0},{0,-1},{-1,0}};
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (grid[i][j]==1) {
                    grid[i][j] = -1;
                    q.push({i,j});
                }
            }
        }
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            for (auto d: dirs) {
                int x = node.first+d.first;
                int y = node.second+d.second;
                if (x<n && x>=0 && y<m && y>=0 && grid[x][y]==0) {
                    grid[x][y] = max(0, grid[node.first][node.second])+1;
                    q.push({x,y});
                }
            }
        } 
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (grid[i][j]==-1) {
                    grid[i][j] = 0;
                }
            }
        } return grid;
    }
};