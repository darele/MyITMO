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

void siguiente(vector <string> &v) {
    vector <string> aux = v;
    reverse(aux.begin(), aux.end());
    int n = v.size();
    for (int i = 0; i < n; i++) {
        v[i] += "0";
        aux[i] += "1";
        v.push_back(aux[i]);
    }
}

void solve() {
    int n;
    cin >> n;
    vector <string> v;
    v.reserve(1 << n);
    v.push_back("0");
    v.push_back("1");
    REP(1, n) {
        siguiente(v);
    }
    REP(0, v.size()) {
        reverse(v[i].begin(), v[i].end());
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