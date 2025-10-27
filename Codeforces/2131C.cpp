#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;
        vector<long long> A(n), B(n);
        for (int i = 0; i < n; i++) cin >> A[i];
        for (int i = 0; i < n; i++) cin >> B[i];

        for (int i = 0; i < n; i++) A[i] = min(A[i] % k, (k - A[i] % k) % k);
        for (int i = 0; i < n; i++) B[i] = min(B[i] % k, (k - B[i] % k) % k);

        sort(A.begin(), A.end());
        sort(B.begin(), B.end());

        bool ok = (A == B);
        cout << (ok ? "YES" : "NO") << "\n";
    }
}
