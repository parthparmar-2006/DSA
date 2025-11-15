#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;

        if (n % 2 != 0 || n < 4) {
            cout << -1 << "\n";
            continue;
        }
        
        long long minBus = (n + 5) / 6; 
        long long maxBus = n / 4;
        cout << minBus << " " << maxBus << "\n";
    }
}
