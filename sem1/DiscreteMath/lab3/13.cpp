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

ll n, k;

void solve() {
    cin >> n >> k;
    ll fac[n];
    fac[0] = 1;
    for (ll i = 1; i < n; i++) fac[i] = fac[i - 1] * i;
    vector <int> lista;
    lista.reserve(n);
    int i = n - 1;
    while (i >= 0) {
        lista.push_back(k / fac[i]);
        k %= fac[i--];
    }
    n = lista.size();
    vector <bool> vis(n, 0);
    for (i = 0; i < n; i++) {
        int cont = 0;
        for (int j = 0; j < n; j++) {
            if (vis[j]) continue;
            if (cont == lista[i]) {
                vis[j] = 1;
                cont = 0;
                cout << j + 1 << " ";
                break;
            }
            cont++;
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