#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    static vector<int> beautiful;
    static vector<int> precompute() {
        vector<int> ans, mp(7,0);
        Solution().backtrack(0, mp, ans);
        sort(ans.begin(), ans.end());
        return ans;
    }
    void backtrack(int n, vector<int>& mp, vector<int>& ans) {
        if (n>0 && isBeautiful(mp)) ans.push_back(n);
        if (n>1224444) return;
        for (int d=1; d<=6; d++) {
            if (mp[d]<d) {
                mp[d]++;
                backtrack(n*10+d, mp, ans);
                mp[d]--;
            }
        }
    }
    bool isBeautiful(vector<int>& mp) {
        for (int i=1; i<=6; i++) if (mp[i]>0 && i!=mp[i]) return false;
        return true;
    }
    int nextBeautifulNumber(int n) {
        return *upper_bound(beautiful.begin(), beautiful.end(), n);
    }
};

vector<int> Solution::beautiful = Solution::precompute();
