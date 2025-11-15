#include <bits/stdc++.h>
using namespace std;

static const long long MOD = 1'000'000'007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<long long> a(n), b(n);
        for (auto &x : a) cin >> x;
        for (auto &x : b) cin >> x;

        sort(a.begin(), a.end());

        vector<int> c(n);
        for (int i = 0; i < n; i++) {
            // Number of elements in a strictly greater than b[i]
            c[i] = a.end() - upper_bound(a.begin(), a.end(), b[i]);
        }

        sort(c.begin(), c.end());

        long long ans = 1;
        for (int i = 0; i < n; i++) {
            long long ways = c[i] - i;
            if (ways <= 0) {
                ans = 0;
                break;
            }
            ans = (ans * ways) % MOD;
        }

        cout << ans << "\n";
    }
    return 0;
}
