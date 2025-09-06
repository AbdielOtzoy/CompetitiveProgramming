/*
link: https://codeforces.com/problemset/problem/352/A
tags: implementation, greedy, math
*/

#include <bits/stdc++.h>
using namespace std;

#define all(a) (a).begin(), (a).end()

void solve(vector<int> &cards) {
    int c5 = count(all(cards), 5);
    int c0 = count(all(cards), 0);

    if(c0 == 0){
        cout << -1 << endl;
        return;
    }

    if(c5 < 9){
        cout << 0 << endl;
        return;
    }

    int m9 = (c5 / 9) * 9;

    string s5(m9, '5');
    string s0(c0, '0');
    cout << s5 << s0 << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> cards(n);
    for (int i = 0; i < n; i++) {
        cin >> cards[i];
    }
    solve(cards);

    return 0;
}