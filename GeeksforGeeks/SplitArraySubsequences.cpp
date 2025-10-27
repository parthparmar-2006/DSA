#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool isPossible(vector<int>& arr, int k) {
        unordered_map<int,int> freq, end;
        
        for(int x : arr) freq[x]++;
        
        for(int x : arr) {
            if(freq[x] == 0) continue; 
            
            if(end[x-1] > 0) {
                end[x-1]--;
                end[x]++;
                freq[x]--;
            }
            else {
                bool canForm = true;
                for(int i = 0; i < k; i++) {
                    if(freq[x+i] <= 0) {
                        canForm = false;
                        break;
                    }
                }
                if(!canForm) return false;
                for(int i = 0; i < k; i++) freq[x+i]--;
                end[x+k-1]++; 
            }
        }
        
        return true;
    }
};
