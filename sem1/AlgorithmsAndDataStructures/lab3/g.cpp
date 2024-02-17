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
#define tam 20000005

using namespace std;

bitset <tam> vis;
set <int> primos;

void sieve() {
    vis.set();
    for (ll i = 2; i * i <= tam; i++) {
        if (vis[i]) {
            for (ll j = i * i; j <= tam; j += i) {
                vis[j] = 0;
            }
        }
    }
    for (int i = 2; i < tam; i++) {
        if (vis[i]) primos.insert(i);
    }
}

void solve() {
    sieve();
    int n;
    cin >> n;
    int x;
    REP(0, n) {
        cin >> x;
        if (primos.find(x) != primos.end()) cout << "YES\n";
        else cout << "NO\n";
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