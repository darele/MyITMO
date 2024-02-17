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
#define tam 105

using namespace std;

ll dp[tam][tam];

void gen() {
    REP(0, tam) dp[0][i] = 1;
    for (int i = 1; i < tam; i++) {
        dp[i][i] = 1;
    }
    for (int i = 1; i < tam - 1; i++) {
        for (int j = i - 1; j > 0; j--) {
            dp[i][j] = dp[i][j + 1] + dp[i - j][j];
        }
    }
}

void solve() {
    ll n, r;
    cin >> n >> r;
    gen();
    r++;
    int i = 1;
    vector <int> ans;
    ans.reserve(n);
    int sum = 0;
    int next = 1;
    while (r) {
        if (dp[n - sum - next][next] <= r) {
            r -= dp[n - sum - next][next];
            if (r == 0) {
                ans.push_back(next);
                if (n - sum - next > 0) ans.push_back(n - sum - next);
            }
            next++;
        } else {
            ans.push_back(next);
            sum += next;
        }
    }
    for (int i = 0; i < ans.size() - 1; i++) cout << ans[i] << "+";
    cout << ans.back() << endl;
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