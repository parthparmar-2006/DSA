#include<bits/stdc++.h>
using namespace std;
long long helper(vector<int>& a) {
    long long op=0, mid=a.size()/2;
    for (int i=0; i<a.size(); i++) {
        op += abs(a[mid]-a[i])-abs(mid-i);
    } return op;
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;  
        cin >> n;
        vector<int> a, b; 
        for (int i=0; i<n; i++) {
            char ch;
            cin >> ch;
            if (ch=='a') a.push_back(i);
            else b.push_back(i);
        }
        cout << min(helper(a), helper(b)) << endl;
    }
}