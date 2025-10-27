#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int maxi=0;
        for (int i=0; i<nums.size(); i++) {
            unordered_set<int> odd, even;
            for (int j=i; j<nums.size(); j++) {
                if (nums[j]%2) odd.insert(nums[j]);
                else even.insert(nums[j]);
                int o=odd.size(), e=even.size();
                if (o==e) maxi = max(maxi, j-i+1);
            }
        } return maxi;
    }
};