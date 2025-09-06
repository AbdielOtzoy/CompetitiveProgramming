/*
link: https://codeforces.com/problemset/problem/358/D
tags: dp, implementation
bottom-up dp
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n; i++) cin >> c[i];
    
    vector<vector<long long>> dp(n, vector<long long>(n, 0));
    for (int i = 0; i < n; i++) dp[i][i] = a[i];
    
    for (int len = 2; len <= n; len++) {
        for (int l = 0; l <= n - len; l++) {
            int r = l + len - 1;
            for (int k = l; k <= r; k++) {
                long long joy;
                if (k == l && k == r) {
                    joy = a[k];
                } else if (k == l) {
                    joy = b[k];
                } else if (k == r) {
                    joy = b[k];
                } else {
                    joy = c[k];
                }
                long long left_dp = (k > l) ? dp[l][k-1] : 0;
                long long right_dp = (k < r) ? dp[k+1][r] : 0;
                dp[l][r] = max(dp[l][r], left_dp + right_dp + joy);
            }
        }
    }
    cout << dp[0][n-1] << "\n";
    return 0;
}
