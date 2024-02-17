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
#define lim 100005
#define mod 1000000007ll
#define k 31ll

using namespace std;

int n;
ll p[lim];
ll h[lim];

ll hash_substring(int l, int r) {
    return (h[r] - h[l - 1] * p[r - l + 1] + mod * mod) % mod;
}

void solve() {
    string s;
    cin >> s;
    n = s.size();
    REP(0, s.size()) {
        s[i] -= 'a';
        s[i]++;
    }
    p[0] = 1;
    for (int i = 1; i < lim; i++) {
        p[i] = (p[i - 1] * k) % mod;
    }
    h[0] = 0;
    for (int i = 0; i < s.size(); i++) {
        h[i + 1] = (h[i] * k + s[i]) % mod;
    }
    int m;
    cin >> m;
    int a, b, c, d;
    REP(0, m) {
        cin >> a >> b >> c >> d;
        if (hash_substring(a, b) == hash_substring(c, d)) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
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