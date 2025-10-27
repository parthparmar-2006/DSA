#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        int z=0;
        long sum = n*(n+1)/2;
        for (int i=0; i<n; i++) {
            cin >> arr[i];
            if (arr[i]==0) {
                z++;
            } sum -= (arr[i]);
            
        }
        int firstViolation=-1, lastViolation=-1;
        for (int i=0; i<n; i++) {
            if ((arr[i]!=0 && arr[i]!=(i+1)) || (arr[i]==0 && (z>1 || (sum!=(i+1))))) {
                if (firstViolation==-1) firstViolation = i;
                lastViolation = i+1;
            }
        } cout << lastViolation-firstViolation << endl;
    }
}