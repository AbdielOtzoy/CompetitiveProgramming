#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#define REP(i,a,b) for (int i = a; i < b; i++)
const long long MOD = 1e9 + 7;
void fast_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
}

std::vector<std::vector<int>> adj;
std::vector<std::vector<int>> rev_adj;

std::vector<bool> visited;

std::stack<int> order_stack;

std::vector<int> current_scc;

void dfs1(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs1(v);
        }
    }
    order_stack.push(u);
}

void dfs2(int u) {
    visited[u] = true;
    current_scc.push_back(u);
    for (int v : rev_adj[u]) {
        if (!visited[v]) {
            dfs2(v);
        }
    }
}

int main() {
    fast_io();

    int n, m;
    std::cin >> n;
    std::vector<int> p(n+1);
    REP(i, 1, n+1) {
        std::cin >> p[i];
    }
    std::cin >> m;

    adj.resize(n + 1);
    rev_adj.resize(n + 1);
    visited.resize(n + 1);

    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        adj[u].push_back(v);
        rev_adj[v].push_back(u);
    }

    std::fill(visited.begin(), visited.end(), false);
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            dfs1(i);
        }
    }
    std::fill(visited.begin(), visited.end(), false);
    std::vector<std::vector<int>> sccs;

    while (!order_stack.empty()) {
        int u = order_stack.top();
        order_stack.pop();

        if (!visited[u]) {
            current_scc.clear();
            dfs2(u);
            sccs.push_back(current_scc);
        }
    }

    long long total = 0;
    long long ps = 1;
    for (const auto& scc : sccs) {
        int min = 1e9+1;
        long long t = 0;
        for (int node : scc) {
            if (p[node] < min) {
                min = p[node];
                t = 1;
            } else if (p[node] == min) {
                t++;
            }
        }
        total += min;
        ps = (ps * t) % MOD;
    }

    std::cout << total << " " << ps <<std::endl;

    return 0;
}