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

        vector<long long> arr(n);
        unordered_set<int> st;
        bool isIncreasing;
        bool flag = false;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            st.insert(arr[i]);
            if (!flag && i>0 && arr[i]>arr[i-1]) {
                isIncreasing = true;
                flag = true;
            } else if (!flag && i>0 && arr[i]<arr[i-1]) {
                isIncreasing = false;
                flag = true;
            }
        }
            
        if (st.size()==1) {
            cout << 1 << endl;
            continue;
        }

        int cnt = 2;
        for (int i=1; i<n; i++) {
            if ((isIncreasing && arr[i]>=arr[i-1]) || (!isIncreasing && arr[i]<=arr[i-1])) {
                continue;
            } else {
                isIncreasing = !isIncreasing;
                cnt++;
            }
        } cout << cnt << endl;
    }

    return 0;
}
