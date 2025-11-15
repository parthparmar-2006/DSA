#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int mem(int m, int n, string& s1, string& s2, vector<vector<int>>& dp) {
        if (m==-1||n==-1) return 0;
        if (dp[m][n]!=-1) return dp[m][n];
        if (s1[m]==s2[n]) return dp[m][n] = 1+mem(m-1, n-1, s1, s2, dp);
        else return  dp[m][n] = max(mem(m-1, n, s1, s2, dp), mem(m, n-1, s1, s2, dp));
    }
    int minSuperSeq(string &s1, string &s2) {
        // code here
        int m=s1.size(), n=s2.size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        int lcs = mem(m-1, n-1, s1, s2, dp);
        return (m+n-lcs);
    }
};