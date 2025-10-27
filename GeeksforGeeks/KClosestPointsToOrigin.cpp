#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // code here
        priority_queue<pair<double, pair<int, int>>> pq;
        for (int i=0; i<points.size(); i++) {
            double dist = sqrt((double)(points[i][0]*points[i][0]+points[i][1]*points[i][1]));
            pq.push({dist, {points[i][0], points[i][1]}});
            if (pq.size()>k) pq.pop();
        } vector<vector<int>> res;
        while (!pq.empty()) {
            auto node = pq.top();
            res.push_back({node.second.first, node.second.second});
            pq.pop();
        } return res;
    }
};