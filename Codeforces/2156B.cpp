#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, q;
		cin >> n >> q;
		vector<char> arr(21);
		int b=0;
		for (int i=0; i<n; i++) {
			cin >> arr[i];
			if (arr[i]=='B') b++;
		}
		for (int i=0; i<q; i++) {
			long x;
			cin >> x;
			if (b==0) {
				cout << x << endl;
			} else {
				int cnt=0;
				int idx=0;
				while (x>0) {
					if (arr[idx]=='A') x--;
					else x>>=1;
					idx = (idx+1)%n;
					cnt++;
				} cout << cnt << endl;
			}
		}
	}
}