#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s1, s2;
        unordered_map<char, int> mp;
        cin >> s1 >> s2;
        for (auto ch: s1) {
            mp[ch]--;
        }
        for (auto ch: s2) {
            mp[ch]++;
        }
        bool flag = false;
        for (auto i: mp) {
            if (i.second!=0) {
                flag = true;
                break;
            }
        }
        if (flag) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
}
