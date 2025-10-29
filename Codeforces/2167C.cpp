#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        bool e = false, o = false;
        for (int &x : a) {
            cin >> x;
            if (x % 2) o = true;
            else e = true;
        }
        if (e && o) {
            sort(a.begin(), a.end());
        }
        for (int i = 0; i < n; ++i)
            cout << a[i] << " \n"[i + 1 == n];
    }
}
