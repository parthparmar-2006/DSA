#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestNumber(int n) {
        int ans=1,i=2;
        while (ans<n) {
            ans=(1<<i)-1;
            i++;
        } return ans;
    }
};