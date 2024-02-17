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

void imprimir(vector <string> v) {
    REP(0, v.size()) cout << v[i] << "\n";
    RAYA;
}

void siguiente(vector <string> &v, int k) {
    int n = v.size();
    REP(1, k) {
        char c = '0' + i;
        for (int j = 0; j < n; j++) {
            if (i % 2) {
                v.push_back(v[n - j - 1]);
                v.back() += c;
            } else {
                v.push_back(v[j]);
                v.back() += c;
            }
        }
    }
    REP(0, n) {
        v[i] += '0';
    }
}

void solve() {
    int n, k;
    cin >> n >> k;
    int lim = 1;
    for (int i = 0; i < n; i++) lim *= k;
    vector <string> v(k);
    v.reserve(lim);
    REP(0, k) {
        char c = '0' + i;
        v[i] += c;
    }
    REP(1, n) {
        siguiente(v, k);
    }
    for (auto i : v) {
        cout << i << "\n";
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