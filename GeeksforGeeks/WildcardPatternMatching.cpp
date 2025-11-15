#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool mem(int i, int j, string &txt, string &pat, vector<vector<int>> &dp) {
        if (i < 0 && j < 0) return true;
        if (j < 0 && i >= 0) return false;
        if (i < 0 && j >= 0) {
            for (int k = 0; k <= j; k++)
                if (pat[k] != '*') return false;
            return true;
        }

        if (dp[i][j] != -1) return dp[i][j];

        if (pat[j] == txt[i] || pat[j] == '?')
            return dp[i][j] = mem(i - 1, j - 1, txt, pat, dp);
        else if (pat[j] == '*')
            return dp[i][j] = (mem(i - 1, j, txt, pat, dp) || mem(i, j - 1, txt, pat, dp));

        return dp[i][j] = false;
    }

    bool wildCard(string &txt, string &pat) {
        int m = txt.size(), n = pat.size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return mem(m - 1, n - 1, txt, pat, dp);
    }
};
