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

ll C[35][35];

ll combi(int n, int k) {
    if (k == 0) C[n][k] = 1;
    if (n == k) C[n][k] = 1;
    if (C[n][k] != 0) return C[n][k];
    return C[n][k] = combi(n - 1, k - 1) + combi(n - 1, k);
}

void solve() {
    ll n, k, m;
    cin >> n >> k >> m;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            combi(i, j);
        }
    }
    int next = 1;
    vector <int> choose;
    choose.reserve(k);
    while (k > 0) {
        //cout << m << " " << C[n - 1][k - 1] << " " << next << endl;
        if (m < C[n - 1][k - 1]) {
            choose.push_back(next);
            k = k - 1;
        } else {
            m -= C[n - 1][k - 1];
        }
        n = n - 1;
        next++;
    }
    for (auto x : choose) cout << x << " ";
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