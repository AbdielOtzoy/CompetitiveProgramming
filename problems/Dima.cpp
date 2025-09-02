#include <bits/stdc++.h>
using namespace std;

// print pair
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
// print vector
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

// Debugging utilities  
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

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