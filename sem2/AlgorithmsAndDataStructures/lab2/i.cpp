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

using namespace std;

pair <bool, pair <int, int> > dp[105][30005];

void solve() {
    int n, s;
    cin >> n;
    int a[n + 1];
    s = 0;
    REP(0, n) {
        cin >> a[i + 1];
        s += a[i + 1];
    }
    dp[0][0] = {1, {0, 0}};
    int suma = 0;
    int cupones = 0;
    REP(1, n + 1) {
        REP2(0, s + 1) {
            cupones = 0;
            suma = j % 100;
            suma += a[i];
            while (suma >= 100) {
                suma -= 100;
                cupones++;
            }
            if (j - a[i] >= 0 && dp[i - 1][j - a[i]].ff) {
                dp[i][j] = {1, {1, dp[i - 1][j - a[i]].ss.ss + cupones}};
            }
            if (dp[i - 1][j].ss.ss && dp[i - 1][j].ff) {
                dp[i][j] = {1, {0, max(dp[i][j].ss.ss, dp[i - 1][j].ss.ss - 1)}};
            }
        }
    }
    vi ans;
    ans.reserve(n);
    for (int i = 0; i < s + 1; i++) {
        if (dp[n][i].ff) {
            cout << i << "\n" << dp[n][i].ss.ss << " ";
            int j = i;
            int k = n;
            while (k > 0) {
                if (dp[k][j].ss.ff) {
                    j -= a[k];
                } else {
                    ans.push_back(k);
                }
                k--;
            }
            reverse(ans.begin(), ans.end());
            cout << ans.size() << "\n";
            for (int x : ans) cout << x << "\n";
            break;
        }
    }
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