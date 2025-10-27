#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> arr(5, 0);
    for (int i=0; i<n; i++) {
        int v;
        cin >> v;
        arr[v]++;
    }
    arr[1] = max(0, arr[1]-arr[3]);
    arr[1] = arr[1]/4 + (arr[1]%4!=0);
    int pairs = min(arr[2], arr[1]/2+arr[1]%2);
    arr[2] = pairs + (arr[2]-pairs)/2+(arr[2]-pairs)%2;
    arr[1] -= max(0, pairs*2-arr[1]%2);
    cout << arr[1]+arr[2]+arr[3]+arr[4] << endl;

}