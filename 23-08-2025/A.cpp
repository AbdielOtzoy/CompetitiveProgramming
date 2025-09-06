#include <bits/stdc++.h>
using namespace std;

int minSpells(vector<int> &a, int n) {
    int total = accumulate(a.begin(), a.end(), 0);
    int spells = 0;
    int curr_n = n;
    while (curr_n > 0 && total % curr_n != 0) {
        curr_n--;
        spells++;
    }
    return spells;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << minSpells(a, n) << endl;
}
