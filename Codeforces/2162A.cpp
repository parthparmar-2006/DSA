#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<int> arr(n);
		for (int i=0; i<n; i++) {
			cin >> arr[i];
		}
		int maxi=0;
		for (int i=0; i<n; i++) {
			int sum = 0;
			for (int j=i; j<n; j++) {
				sum += arr[j];
				maxi = max(maxi, sum/(j-i+1));
			}
		} cout << maxi << endl;
	}
}