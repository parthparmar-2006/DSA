#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		long long n; 
		cin >> n;
		long long halo=0;
		while (n>=3) {
			if (n%3==2) {
				halo++;
				n -= 2;
				continue;
			}
			halo += n/3;
			n = n/3 + (n%3!=0);
		} cout << halo << endl;
	}
}