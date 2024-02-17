#include <bits/stdc++.h>
#define DBG(x) cerr << #x << "=" << (x) << "\n"
#define RAYA cerr << "======================\n"
#define ll long long
#define ii pair <int, int>
#define dl pair <ll, ll>
#define vi vector <int>
#define vl vector <ll>
#define vii vector <ii>
#define graph vector <vi>
#define ff first
#define ss second
#define REP(a, b) for (int i = a; i < b; i++)
#define REP2(a, b) for (int j = a; j < b; j++)
#define REPS(a, b, c) for (int i = a; i < b; i += c)
#define lim 2010
#define mod 1000000007

using namespace std;

int k, m;
ll dp[lim][lim];
ll t[lim][lim];
ll c[lim];

void solve() {
    cin >> k >> m;
    REP(0, k) {
        cin >> c[i];
    }
    dp[0][0] = dp[1][0] = 1;
    t[0][0] = t[1][0] = 1;
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < k; j++) {
            if (i >= c[j]) {
                t[i][i] += dp[i][i - c[j]];
                t[i][i] %= mod;
            }
        }
        for (int j = 0; j <= i; j++) {
            dp[i][i] += (t[i][i - j] * t[i][j]) % mod;
            dp[i][i] %= mod;
        }
        for (int j = 0; j <= m; j++) {
            dp[i + 1][j] = dp[i][j];
            t[i + 1][j] = t[i][j];
        }
    }
    for (int i = 1; i <= m; i++) {
        cout << t[m][i] << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t = 1;
    //cin >> t;
    while (t--) {
        
        solve();
    }
    return 0;
}