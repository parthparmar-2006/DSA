#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int mem(int i, int m, int n,  vector<vector<int>>& arr, vector<vector<vector<int>>>& dp) {
        if (m<0 || n<0) return -1e8;
        if (i<0) return 0;
        if (dp[i][m][n]>0) return dp[i][m][n];
        return dp[i][m][n] = max(1+mem(i-1, m-arr[i][0], n-arr[i][1], arr, dp), mem(i-1, m, n, arr, dp));
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> arr;
        for (string s: strs) {
            int z=0, o=0;
            for (char ch: s) {
                if (ch=='0') z++;
                else o++;
            }
            arr.push_back({z,o});
        }
        vector<vector<vector<int>>> dp(arr.size(), vector<vector<int>>(m+1, vector<int>(n+1, -1)));
        return max(0, mem(arr.size()-1, m, n, arr, dp));
    }
};