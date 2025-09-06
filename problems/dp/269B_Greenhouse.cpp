
#include <bits/stdc++.h>
using namespace std;

void solve(const vector<int>& p,int n, int m) {
    vector<int> dp(m + 1, 0);
    for (int i = 0; i < n; i ++) {
        int j = p[i];
        for(int k = j; k >= 1; k--) {
            dp[j] = max(dp[j], 1+dp[k]);
        }
    }
    int ans = 0;
    for(int a : dp){
        ans = max(ans, a);
    }
    cout << (n-ans) << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        int s; cin >> s;
        float x; cin >> x;
        p[i] = s;
    }
    solve(p,n,m);
}