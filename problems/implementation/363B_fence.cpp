/*
link: https://codeforces.com/problemset/problem/363/B
tags: implementation, greedy, sliding window
*/
#include <bits/stdc++.h>
#define LOCAL
using namespace std;

void solve(vector<int> &nu, int n, int k) {
    int s = accumulate(nu.begin(), nu.begin()+k, 0);
    int m = s;
    int in = 1;
    for(int i = 1; i < n-(k-1); i++){
        s = s - nu[i-1] + nu[i+k-1];
        if(s < m) {
            m = s;
            in = i+1;
        }
    }
    cout << in << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    int k;
    cin >> n >> k;
    vector<int> nu(n);
    for (int i = 0; i < n; i++) {
        cin >> nu[i];
    }
    solve(nu, n, k);
    return 0;
}