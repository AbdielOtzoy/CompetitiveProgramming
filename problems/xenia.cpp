#include <bits/stdc++.h>
using namespace std;

#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

void solve(vector<int> &s, int n) {
    vector<int> freq(8, 0); 
    for (int x : s) {
        freq[x]++;
    }

    vector<array<int, 3>> res;

    while (freq[1] > 0 && freq[2] > 0 && freq[4] > 0) {
        res.push_back({1,2,4});
        freq[1]--; freq[2]--; freq[4]--;
    }

    while (freq[1] > 0 && freq[2] > 0 && freq[6] > 0) {
        res.push_back({1,2,6});
        freq[1]--; freq[2]--; freq[6]--;
    }

    while (freq[1] > 0 && freq[3] > 0 && freq[6] > 0) {
        res.push_back({1,3,6});
        freq[1]--; freq[3]--; freq[6]--;
    }

    for (int i = 1; i <= 7; ++i) {
        if (freq[i] > 0) {
            cout << -1 << endl;
            return;
        }
    }

    for (auto &group : res) {
        for (int x : group) cout << x << " ";
        cout << '\n';
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    solve(s, n);
    return 0;
}