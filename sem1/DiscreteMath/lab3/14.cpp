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

void solve() {
    int n;
    cin >> n;
    int arr[n];
    ll fac[n];
    fac[0] = 1;
    for (ll i = 1; i < n; i++) fac[i] = fac[i - 1] * i;
    ll ans = 0;
    bool vis[n];
    REP(0, n) vis[i] = 0;
    REP(0, n) {
        cin >> arr[i];
        arr[i]--;
        for (int j = 0; j < arr[i]; j++) {
            if (vis[j]) continue;
            ans += fac[n - 1 - i];
        }
        vis[arr[i]] = 1;
    }
    cout << ans << "\n";
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