/*
link: https://codeforces.com/problemset/problem/189/A
tags: dp, implementation
bottom-up dp
*/

#include <bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for (int i = a; i <= b; i++)

#define ll long long

const ll INF = 1e9;

void solve(int n, int a, int b, int c) {
    vector<int> dp(n+1, -INF);
    dp[0] = 0;

     for (int i = 1; i <= n; i++) {
        if (i >= a) dp[i] = max(dp[i], dp[i - a] + 1);
        if (i >= b) dp[i] = max(dp[i], dp[i - b] + 1);
        if (i >= c) dp[i] = max(dp[i], dp[i - c] + 1);
    }

    cout << dp[n] << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, a, b ,c;
    cin >> n >> a >> b >> c;
    solve(n, a, b ,c);
    return 0;
}