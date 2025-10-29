#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2) {
        long long mini = INT_MAX, cost=0;
        int n = nums1.size();
        for (int i=0; i<n; i++) {
            mini = min(mini, (long long)abs(nums2[n]-nums1[i]));
            mini = min(mini, (long long)abs(nums2[n]-nums2[i]));
            if (min(nums1[i], nums2[i])<nums2[n] && max(nums1[i], nums2[i])>nums2[n]) {
                mini = 0;
            }
            cost += abs(nums1[i]-nums2[i]);
        } return cost+mini+1;
    }
};
