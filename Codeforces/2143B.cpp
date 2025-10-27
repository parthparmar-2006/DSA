#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n,k;
		cin >> n>>k;
		vector<long long> a(n);
		vector<int> arr(k);
		for (int i=0; i<n; i++) {
			cin >> a[i];
		}
		for (int i=0; i<k; i++) cin >> arr[i];
		sort(a.rbegin(), a.rend());
		sort(arr.begin(), arr.end());
		int idx=0, i=0;
		long long cost=0;
		while (idx<k && (n-i)>=arr[idx]) {
			for (int j=i; j<(i+arr[idx]-1); j++) {
				cost += a[j];
			} i+=arr[idx];
			idx++;
		} while (i<n) {
			cost += a[i++];
		} cout << cost << endl;
	}
}