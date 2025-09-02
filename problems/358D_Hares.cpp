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
    
    // dp[l][r] = maximum joy from feeding all hares in range [l, r]
    // assuming all hares outside this range are hungry
    vector<vector<long long>> dp(n, vector<long long>(n, 0));
    
    // Base case: single hares
    for (int i = 0; i < n; i++) {
        dp[i][i] = a[i]; // both neighbors hungry (or don't exist)
    }
    
    // Fill DP table for increasing interval lengths
    for (int len = 2; len <= n; len++) {
        for (int l = 0; l <= n - len; l++) {
            int r = l + len - 1;
            
            // Try feeding each hare k in [l, r] as the last one
            for (int k = l; k <= r; k++) {
                long long joy;
                
                if (k == l && k == r) {
                    // Single hare case (already handled above)
                    joy = a[k];
                } else if (k == l) {
                    // Leftmost hare: has 1 fed neighbor on right, 0 on left
                    joy = b[k];
                } else if (k == r) {
                    // Rightmost hare: has 1 fed neighbor on left, 0 on right
                    joy = b[k];
                } else {
                    // Middle hare: has fed neighbors on both sides
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