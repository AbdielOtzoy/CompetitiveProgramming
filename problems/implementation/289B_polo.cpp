/*
link: https://codeforces.com/problemset/problem/289/B
tags: implementation, sorting, greedy
*/
#include <bits/stdc++.h>
using namespace std;

#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

void solve(vector<int> &a, int n, int d) {
    sort(all(a));

    int m = a[sza(a)/2];
    int c = 0;
    for(int i = 0; i < n; i++) {
        int ai = a[i];
        int r = abs(ai - m);
        if(r%d != 0) {
            cout << -1 << endl;
            return;
        }
        c += r/d;
    }
    cout << c << endl;   
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m, d;
    cin >> n >> m >> d;
    vector<int> a(n*m);
    for (int i = 0; i < n*m; i++) {
        cin >> a[i];
    }
    solve(a, n*m, d);
}