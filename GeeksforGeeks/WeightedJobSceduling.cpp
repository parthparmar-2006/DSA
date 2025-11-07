#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int maxProfit(vector<vector<int>>& jobs) {
        sort(jobs.begin(), jobs.end(), [](auto &a, auto &b){
            return a[1] < b[1];   
        });

        vector<pair<int,int>> dp;
        dp.push_back({0, 0});   

        int maxi = 0;
        for (auto &job : jobs) {
            int start = job[0];
            int end   = job[1];
            int val   = job[2];

            int l = 0, r = dp.size() - 1;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (dp[mid].first <= start)
                    l = mid + 1;
                else
                    r = mid - 1;
            }

            int bestBefore = dp[r].second;
            int currProfit = bestBefore + val;
            maxi = max(maxi, currProfit);

            if (currProfit > dp.back().second) {
                dp.push_back({end, currProfit});
            }
        }

        return maxi;
    }
};
