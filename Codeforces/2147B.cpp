#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> res(2*n);
        for (int i=0; i<n; i++) {
            res[i] = n-i;
        }
        res[n] = n;
        for (int i=n+1; i<2*n; i++) {
            res[i] = i-n;
        }
        for (auto i: res) {
            cout << i << " ";
        } cout << endl;
    }
}