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
#define tam 9*1005
#define mod 1000000007

using namespace std;

ll dp[1005][tam];

void solve() {
    ll k, s;
    cin >> k >> s;
    dp[0][0] = 1;
    for (int i = 1; i <= k; i++) {
        for (int j = 0; j <= s; j++) {
            for (int l = 0; l < 10; l++) {
                if (j - l >= 0) {
                    dp[i][j] += dp[i - 1][j - l];
                    dp[i][j] %= mod;
                }
            }
        }
    }
    cout << dp[k][s] << "\n";
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