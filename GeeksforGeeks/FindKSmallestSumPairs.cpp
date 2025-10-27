#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<vector<int>> kSmallestPair(vector<int> &arr1, vector<int> &arr2, int k) {
        // code here
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({arr1[0]+arr2[0], {0,0}});
        set<pair<int, int>> st;
        st.insert({0,0});
        vector<vector<int>> res;
        while (k>0 && !pq.empty()) {
            auto node = pq.top();
            pq.pop();
            int x=node.second.first, y=node.second.second;
            res.push_back({arr1[x], arr2[y]});
            if ((x+1)<arr1.size() && !st.count({x+1, y})) {
                pq.push({arr1[x+1]+arr2[y], {x+1, y}});
                st.insert({x+1, y});
            } 
            if ((y+1)<arr2.size() && !st.count({x, y+1})) {
                pq.push({arr1[x]+arr2[y+1], {x, y+1}});
                st.insert({x, y+1});
            } k--;
        } return res;
    }
};
