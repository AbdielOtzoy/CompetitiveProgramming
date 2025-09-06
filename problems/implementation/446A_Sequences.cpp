/*
Problema 446A - Sequences
link: https://codeforces.com/problemset/problem/446/A
tags: implementation, greedy
*/
#include <bits/stdc++.h>
using namespace std;

void solve(vector<int>& a, int n) {
    vector<int> l(n, 1), r(n, 1);
    for (int i = 1; i < n; i++) {
        if (a[i] > a[i-1]) l[i] = l[i-1] + 1;
    }
    for (int i = n-2; i >= 0; i--) {
        if (a[i] < a[i+1]) r[i] = r[i+1] + 1;
    }
    int ans = 1;
    for (int i = 0; i < n; i++) {
        ans = max(ans, l[i]);
    }
    for (int i = 0; i < n; i++) {
        int current = 1;
        if (i > 0) current = max(current, l[i-1] + 1);
        if (i < n-1) current = max(current, r[i+1] + 1);
        if (i > 0 && i < n-1 && a[i-1] + 1 < a[i+1]) {
            current = max(current, l[i-1] + 1 + r[i+1]);
        }
        ans = max(ans, current);
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    solve(a, n);
}
