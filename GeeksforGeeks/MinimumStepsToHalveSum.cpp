#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int minOperations(vector<int>& arr) {
        // code here
        priority_queue<double> pq;
        double sum=0, cnt=0;
        for (int i: arr) {
            pq.push(i);
            sum += i;
        }
        double target = (double)sum/2;
        while (sum>target) {
            double n = pq.top();
            pq.pop();
            sum -= (n/2);
            pq.push(n/2);
            cnt++;
        } return cnt;
    }
};