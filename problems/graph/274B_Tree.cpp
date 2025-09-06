/*
link: https://codeforces.com/problemset/problem/274/B
tags: dfs, trees, implementation
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long

pair<ll, ll> dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& w) {
    pair<ll, ll> indec = {0, 0}; 
    for (int child : adj[node]) {
        pair<ll, ll> Temp = {0, 0}; 
        if (child != parent) { 
           Temp = dfs(child, node, adj, w);
        }
        indec.first = max(indec.first, Temp.first);
        indec.second = max(indec.second, Temp.second);
    }

    int a = w[node] + indec.first - indec.second;
    if (a > 0) indec.second += a;
    if (a < 0) indec.first += -a;
    return indec;
}

void solve(vector<vector<int>>& adj, vector<int>& w) {
    pair<ll, ll> indec = dfs(1, -1, adj, w);
    cout << indec.first + indec.second << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }

    vector<int> w(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }

    solve(adj, w);
}
