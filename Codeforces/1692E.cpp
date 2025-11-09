#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, s;
        cin >> n >> s;

        vector<int> a(n);
        int total = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            total += a[i];
        }

        if (total < s) {
            cout << -1 << "\n";
            continue;
        }

        int i = 0, curr = 0, longest = 0;
        for (int j = 0; j < n; ++j) {
            curr += a[j];

            while (curr > s) {
                curr -= a[i];
                i++;
            }

            if (curr == s) {
                longest = max(longest, j - i + 1);
            }
        }

        cout << (n - longest) << "\n";
    }

    return 0;
}
