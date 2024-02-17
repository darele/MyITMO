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

ll gcd(ll a, ll b) {return b == 0 ? a : gcd(b, a % b);}

ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

void solve() {
    ll x, y;
    cin >> x >> y;
    vii v;
    ll tam = 0;
    for (ll i = 1; i * i <= y; i++) {
        tam++;
    }
    tam *= 2;
    v.reserve(tam);
    ll a, b;
    for (ll i = 1; x * i <= y && y / i >= x && x * i <= y / i; i++) {
        a = x * i;
        b = y / i;
        if (lcm(a, b) == y && gcd(a, b) == x) {
            v.push_back({a, b});
            if (b != a) v.push_back({b, a});
        }
    }
    sort(v.begin(), v.end());
    REP(0, v.size()) {
        cout << v[i].ff << " " << v[i].ss << "\n";
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