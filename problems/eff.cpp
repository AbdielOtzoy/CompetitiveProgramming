#include <bits/stdc++.h>
using namespace std;

void solve(const vector<int> &e, const vector<int> &q) {
    int n = e.size();

    // Guardamos las posiciones en un vector para O(1) acceso
    vector<int> pos(n + 1); // posiciones desde 1 a n
    for (int i = 0; i < n; ++i) {
        pos[e[i]] = i + 1; // indexado desde 1
    }

    long long accv = 0, accp = 0;
    for (int el : q) {
        int index = pos[el];
        accv += index;
        accp += (n + 1 - index);
    }

    cout << accv << " " << accp << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<int> e(n);
    for (int i = 0; i < n; i++) {
        cin >> e[i];
    }

    int m;
    cin >> m;
    vector<int> q(m);
    for (int i = 0; i < m; i++) {
        cin >> q[i];
    }

    solve(e, q);
    return 0;
}
