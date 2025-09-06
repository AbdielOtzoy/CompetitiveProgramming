/*
link: https://codeforces.com/problemset/problem/118/D
tags: dp, implementation
bottom-up dp
z[i][j][0] = number of ways to arrange i footmen and j horse
z[i][j][1] = number of ways to arrange i footmen and j horse
ans = z[n1][n2][0] + z[n1][n2][1]
*/
#include <bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for (int i = a; i <= b; i++)
#define ll long long

const ll MOD = 100000000;

void solve(int n1, int n2, int k1, int k2) {
    vector<vector<vector<ll>>> z(n1+1, vector<vector<ll>>(n2+1, vector<ll>(2, 0))); 
    z[0][0][0] = 1;
    z[0][0][1] = 1;
    REP(i, 0, n1) {
        REP(j, 0, n2) {
            if(i == 0 && j == 0) continue;
            if(i > 0) { 
                REP(consecutive, 1, min(k1, i)) {
                    if(i - consecutive == 0 && j == 0) {
                        if(i <= k1) z[i][j][0] = (z[i][j][0] + 1) % MOD;
                    } else if(i - consecutive >= 0 && j > 0) {
                        z[i][j][0] = (z[i][j][0] + z[i - consecutive][j][1]) % MOD;
                    }
                }
            }
            if(j > 0) {
                REP(consecutive, 1, min(k2, j)) {
                    if(j - consecutive == 0 && i == 0) {
                        if(j <= k2) z[i][j][1] = (z[i][j][1] + 1) % MOD;
                    } else if(j - consecutive >= 0 && i > 0) {
                        z[i][j][1] = (z[i][j][1] + z[i][j - consecutive][0]) % MOD;
                    }
                }
            }
        }
    }
    ll result = (z[n1][n2][0] + z[n1][n2][1]) % MOD;
    cout << result << endl;
}

int main() {
    int n1, n2, k1, k2; 
    cin >> n1 >> n2 >> k1 >> k2;
    solve(n1, n2, k1, k2);
    return 0;
}
