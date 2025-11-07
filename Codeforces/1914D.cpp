#include <bits/stdc++.h>
using namespace std;

long long bestCost = 0;

struct Item {
    long long val;
    int type;   
    int idx;   
};

void dfs(vector<Item>& arr, int pos, long long curCost,
         vector<bool>& usedType, vector<bool>& usedIndex)
{
    if (pos == (int)arr.size()) {
        bestCost = max(bestCost, curCost);
        return;
    }

    dfs(arr, pos + 1, curCost, usedType, usedIndex);

    int t = arr[pos].type;
    int i = arr[pos].idx;

    if (!usedType[t] && !usedIndex[i]) {
        usedType[t] = true;
        usedIndex[i] = true;

        dfs(arr, pos + 1, curCost + arr[pos].val, usedType, usedIndex);

        usedType[t] = false;
        usedIndex[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> aq, bq, cq;

        auto pushToPQ = [&](auto &pq, long long x, int idx) {
            if ((int)pq.size() < 3) pq.push({x, idx});
            else if (x > pq.top().first) {
                pq.pop();
                pq.push({x, idx});
            }
        };

        for (int i = 0; i < n; i++) {
            long long x; cin >> x;
            pushToPQ(aq, x, i);
        }

        for (int i = 0; i < n; i++) {
            long long x; cin >> x;
            pushToPQ(bq, x, i);
        }

        for (int i = 0; i < n; i++) {
            long long x; cin >> x;
            pushToPQ(cq, x, i);
        }

        vector<Item> arr;

        while (!aq.empty()) {
            arr.push_back({aq.top().first, 1, aq.top().second});
            aq.pop();
        }
        while (!bq.empty()) {
            arr.push_back({bq.top().first, 2, bq.top().second});
            bq.pop();
        }
        while (!cq.empty()) {
            arr.push_back({cq.top().first, 3, cq.top().second});
            cq.pop();
        }

        bestCost = 0;
        vector<bool> usedType(4, false);   
        vector<bool> usedIndex(n, false);  

        dfs(arr, 0, 0, usedType, usedIndex);

        cout << bestCost << "\n";
    }
}
