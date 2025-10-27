#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		unordered_map<int, int> mp;
		for (int i=0; i<n; i++) {
			int v; cin >> v;
			mp[v] = i;
		}
		int left = mp[n], right=mp[n--];
		bool flag = false;
		while (n>0) {
			if (mp[n]+1==left){
				left--;
			} else if (mp[n]-1==right) {
				right++;
			} else {
				flag = true;
				break;
			} n--;
		}
		if (flag) {
			cout << "NO" << endl;
		} else cout << "YES" << endl;
	}
}