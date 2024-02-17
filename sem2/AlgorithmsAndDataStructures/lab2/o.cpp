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
#define inf 100000000

using namespace std;

pair <bool, int> dp[105][10005];

void solve() {
    int n, s;
    cin >> n >> s;
    int arr[n + 1];
    REP(0, n) cin >> arr[i + 1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= s; j++) {
            dp[i][j] = {false, inf};
        }
    }
    dp[0][0] = {true, 0};
    REP(1, n + 1) {
        REP2(0, s + 1) {
            dp[i][j] = dp[i - 1][j];
            if (j - arr[i] >= 0) {
                if (dp[i - 1][j - arr[i]].ss + 1 < dp[i][j].ss) {
                    dp[i][j] = {true, dp[i - 1][j - arr[i]].ss + 1};
                }
            }
        }
    }
    cout << (dp[n][s].ss == inf ? 0 : dp[n][s].ss) << "\n";
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