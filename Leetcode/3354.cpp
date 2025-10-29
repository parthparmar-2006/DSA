#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size(), sum = 0, sum2 = 0;
        for (int i: nums) sum += i;
        if (sum == 0) return n*2;
        int c = 0;
        for (int i=0; i<n; i++) {
            if (nums[i]==0) {
                int diff = abs(2*sum2-sum);
                if (diff==0) c+=2;
                else if (diff==1) c+=1;
            } sum2 += nums[i];
        } return c;
    }
};