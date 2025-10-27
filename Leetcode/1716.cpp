#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int totalMoney(int n) {
        int r=n/7, m=n%7;
        int x=28*r + ((r)*(r-1)/2)*7;
        int y=m*(m+1)/2 + m*r;
        return x+y;
    }
};