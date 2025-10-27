#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;  
        cin >> n;
        vector<int> arr(n);
        int odd=0;
        for (int i=0; i<n; i++) {
            cin >> arr[i];
            if (arr[i]%2) odd++;
        }
        if (odd==0) {
            cout << 0 << endl;
            continue;
        }
        odd /= 2;
        sort(arr.begin(), arr.end());
        long long cost=0;
        for (int i=0; i<n; i++) {
            if (arr[i]%2 && odd>0) {
                odd--;
                continue;
            } cost += arr[i];
        }
        cout << cost << endl;
    }
}