#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string res;
        while (num>0) {
            int n = min(9, sum);
            res.push_back(n+'0');
            sum -= n;
            num--;
        } return sum==0? res: "";
    }
};
