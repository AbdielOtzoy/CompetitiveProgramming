/*
Problema 450A - Jzzhu and Sequences
link: https://codeforces.com/problemset/problem/450/A
tags: implementation, math
*/
#include <bits/stdc++.h>
using namespace std;

#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

void solve(vector<int> &a,int n, int m) {
    int b = 0;
    int in = 0;
    for(int i = 0; i < n; i++){
        int el = ceil((double)a[i] / m);
        if (el >= b) {
            b = el;
            in = i;
        }
    }
    in++;
    cout << in << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    solve(a, n, m);
    return 0;
}