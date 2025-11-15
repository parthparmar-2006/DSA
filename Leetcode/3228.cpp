#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxOperations(string s) {
        int total=0, prev=0, curr=0;
        bool flag = false;
        for (char ch: s) {
            if (ch=='0'&&flag) {
                total += curr+prev;
                prev += curr;
                curr = 0;
                flag = false;
            } 
            if (ch=='1') {
                curr++;
                flag = true;
            }
        } return total;
    }
};