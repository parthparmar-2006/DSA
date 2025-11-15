#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int mem(int i, int buy, vector<int>& arr, vector<vector<int>>& dp) {
        if (i>=arr.size()) return 0;
        if (dp[i][buy]!=-1) return dp[i][buy];
        if (buy) {
            return dp[i][buy] = max(mem(i+1, 0, arr, dp)-arr[i], mem(i+1, buy, arr, dp));
        } else {
            return dp[i][buy] = max(mem(i+2, 1, arr, dp)+arr[i], mem(i+1, buy, arr, dp));
        }
    }
    int maxProfit(vector<int>& arr) {
        // code here
        vector<vector<int>> dp(arr.size()+1, vector<int>(2, -1));
        return mem(0, 1, arr, dp);
    }
};