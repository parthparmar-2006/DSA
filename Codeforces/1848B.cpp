#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> c(n+1);
        for (int i = 1; i <= n; i++) cin >> c[i];
        
        vector<int> prev(k+1, 0);
        vector<pair<int,int>> v(k+1, {0,0});

        auto upd = [&](int color, int g) {
            auto &max1 = v[color].first;
            auto &max2 = v[color].second;

            if (g >= max1) {
                max2 = max1;
                max1 = g;
            } else if (g > max2) {
                max2 = g;
            }
        };

        for (int i = 1; i <= n; i++) {
            int color = c[i];
            int gap_inside = i - prev[color] - 1;
            upd(color, gap_inside);
            prev[color] = i;
        }

        for (int color = 1; color <= k; color++) {
            int gap_outside = n - prev[color];
            upd(color, gap_outside);
        }

        int ans = INT_MAX;
        for (int color = 1; color <= k; color++) {
            int max1 = v[color].first;
            int max2 = v[color].second;

            int best = max(max1 / 2, max2);
            ans = min(ans, best);
        }

        cout << ans << "\n";
    }
    return 0;
}
