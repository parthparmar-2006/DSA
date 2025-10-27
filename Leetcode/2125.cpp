#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev=0, total=0;
        for (string s: bank) {
            int cnt=0;
            for (auto ch: s) cnt+=ch=='1';
            total += (prev*cnt);
            if (cnt>0) prev = cnt;
        } return total;
    }
};