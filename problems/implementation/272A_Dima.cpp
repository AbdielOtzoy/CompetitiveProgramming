/*
link: https://codeforces.com/problemset/problem/272/A
tags: implementation
*/
#include <bits/stdc++.h>
using namespace std;

#define all(a) (a).begin(), (a).end()

void solve(const vector<int> &nu, int n) {
    int sum =  accumulate(all(nu), 0);
    sum %= (n+1);
    if (sum == 0) sum = n+1;
    int a = 2+n;
    int t = 0;
    for (int i = 1; i <= 5; i++) {
        if((sum+i) == a) {
            a += n + 1;
            continue;
        }
        t++;
    }
    cout << t << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> nu(n);
    for (int i = 0; i < n; i++) {
        cin >> nu[i];
    }
    solve(nu, n);

    return 0;
}