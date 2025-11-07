#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        long long n;
        int m;
        cin >> n >> m;

        vector<long long> a(m);
        for (int i = 0; i < m; i++) {
            cin >> a[i];
        }

        sort(a.begin(), a.end());

        vector<long long> gaps;

        for (int i = 1; i < m; i++) {
            long long g = a[i] - a[i - 1] - 1;
            if (g > 0) gaps.push_back(g);
        }

        long long g = (a[0] + n) - a[m - 1] - 1;
        if (g > 0) gaps.push_back(g);

        sort(gaps.rbegin(), gaps.rend()); 

        long long saved = 0;
        long long days = 0;

        for (long long gap : gaps) {
            long long rem = gap - 2 * days;
            if (rem <= 0) continue;

            if (rem == 1) {
                saved += 1;
                days += 2;
            } else {
                saved += rem - 1;
                days += 2;
            }
        }

        cout << n - saved << "\n";
    }

    return 0;
}
