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
    vector <string> aux2 = v;
    int n = v.size();
    int j = 0;
    REP(0, n) {
        v[i] += (j + '0');
        j++;
        j %= 3;
    }
    j = 1;
    REP(0, n) {
        aux[i] += (j + '0');
        j++;
        j %= 3;
    }
    j = 2;
    REP(0, n) {
        aux2[i] += (j + '0');
        j++;
        j %= 3;
    }
    REP(0, n) {
        v.push_back(aux[i]);
    }
    REP(0, n) {
        v.push_back(aux2[i]);
    }
}

void solve() {
    int n;
    cin >> n;
    int lim = 3;
    REP(1, n) lim *= 3;
    vector <string> v;
    v.reserve(lim);
    v.push_back("0");
    v.push_back("1");
    v.push_back("2");
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