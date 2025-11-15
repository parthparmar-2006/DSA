#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int mem(int m, int n, string &s1, string &s2, string &s3, vector<vector<int>>& dp) {
        int i = m + n;
        if (i == 0) return 1;
        if (dp[m][n] != -1) return dp[m][n];
        if (m>0 && s3[i-1]==s1[m-1]) if (mem(m-1, n, s1, s2, s3, dp)==1) return dp[m][n] = 1;
        if (n>0 && s3[i-1]==s2[n-1]) if (mem(m, n-1, s1, s2, s3, dp)==1) return dp[m][n] = 1;
        return dp[m][n]=0;
    }
    bool isInterleave(string &s1, string &s2, string &s3) {
        if (s1.size()+s2.size()!=s3.size()) return false;
        vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1, -1));
        return mem(s1.size(), s2.size(), s1, s2, s3, dp)==1;
    }
};
