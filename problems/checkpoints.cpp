#include <bits/stdc++.h>
#define LOCAL
using namespace std;

#define REP(i,a,b) for (int i = a; i < b; i++)

#define ll long long
#define all(a) (a).begin(), (a).end()

const ll MOD = 1e9 + 7;
const ll INF = 1e9;

vector<bool> visited;
vector<bool> inStack;
vector<vector<int>> adj;
int startNode;
int solNum = 1;
int minTemp = INF;
int totalPrice = 0;

bool dfs(int s) {
    visited[s] = true;
    inStack[s] = true;

    for (auto u : adj[s]) {
        if (!visited[u]) {
            if (dfs(u)) return true;
        }
        else if (inStack[u] && u == startNode) {
            return true;
        }
    }

    inStack[s] = false;
    return false;
}

void solve(vector<int> &p, vector<vector<int>> &graph) {
    adj = graph;
    int totalNodes = adj.size();
    vector<bool> totalVisited(totalNodes, false);
    vector<int> priceTemp(totalNodes, INF);

    REP(node, 1, totalNodes) {
        if (totalVisited[node]) continue; 
        startNode = node;
        visited.assign(totalNodes, false);
        inStack.assign(totalNodes, false);
        minTemp = INF;

        if (dfs(node)) {
            REP(i, 1, totalNodes) {
                if (visited[i]) {
                    totalVisited[i] = true;
                    priceTemp[i] = p[i-1];
                }
                if (visited[i] && p[i-1] < minTemp) {
                    minTemp = p[i-1];
                }
            }
            int cantidad = count(all(priceTemp), minTemp);
            solNum += cantidad-1;
            totalPrice += minTemp;

        } else {
            totalPrice += p[node-1];
        }
    }

    cout << totalPrice << " " << solNum << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n;
    vector<int> p(n);
    REP(i, 0, n) {
        cin >> p[i];
    }
    cin >> m;
    vector<vector<int>> adj(n+1);
    REP(i, 0, m){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    solve(p, adj);
    return 0;
}