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

int n, s;
pair <bool, int> dp[105][10005];

void solve() {
    
    cin >> n >> s;
    int a[n + 1];
    REP(0, n) {
        cin >> a[i + 1];
    }
    dp[0][0] = {1, 0};
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= s; j++) {
            if (dp[i - 1][j].ff) {
                dp[i][j] = {1, 0};
            }
            if (j - a[i] >= 0) {
                if (dp[i - 1][j - a[i]].ff) {
                    dp[i][j] = {1, a[i]};
                }
            }
        }
    }
    int mayor = 0;
    for (int i = 0; i <= s; i++) {
        if (dp[n][i].ff) {
            mayor = i;
        }
    }
    cout << mayor << "\n";
    vi ans;
    ans.reserve(n);
    int indice = n;
    while (indice > 0) {
        if (dp[indice][mayor].ss > 0) ans.push_back(dp[indice][mayor].ss);
        mayor = mayor - dp[indice][mayor].ss;
        indice--;
    }
    cout << ans.size() << "\n";
    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i] << " ";
    }
    cout << "\n";
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