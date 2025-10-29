#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >>n>>k;
    vector<int> a(n), b(n);
    for (int i=0; i<n; i++) cin >> a[i];
    for (int i=0; i<n; i++) cin >> b[i];
    int cookies = 0;
    bool flag = true;
    while (flag) {
        for (int i=0; i<n; i++) {
            if (a[i]<=b[i]) b[i]-=a[i];
            else if (a[i]<=(b[i]+k)) {
                k-=(a[i]-b[i]);
                b[i]=0; 
            } else {
                flag = false;
            }
        } if (flag) cookies++;
    } cout << cookies << endl;
}
