#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solve(int i, int j, int k, vector<int> &pref, vector<vector<int>> &dp) {
        if (i >= j) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        int res = INT_MAX;
        for (int m = i; m < j; m += (k - 1)) {
            res = min(res,
                solve(i, m, k, pref, dp) +
                solve(m + 1, j, k, pref, dp)
            );
        }

        if ((j - i) % (k - 1) == 0)
            res += pref[j + 1] - pref[i];

        return dp[i][j] = res;
    }

    int mergeStones(vector<int> &stones, int k) {
        int n = stones.size();
        if ((n - 1) % (k - 1) != 0) return -1;

        vector<int> pref(n + 1);
        for (int i = 0; i < n; i++)
            pref[i + 1] = pref[i] + stones[i];

        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(0, n - 1, k, pref, dp);
    }
};
