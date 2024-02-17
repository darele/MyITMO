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
#define lim 1010

using namespace std;

ll a[lim];
ll c[lim];
ll p[lim];
ll q[lim];

void solve() {
    int k;
    cin >> k;
    REP(0, k) {
        cin >> a[i];
    }
    REP(1, k + 1) {
        cin >> c[i];
    }
    q[0] = 1;
    for (int i = 1; i <= k; i++) {
        q[i] = -c[i];
    }
    for (int i = 0; i < k; i++) {
        p[i] = a[i];
        for (int j = 1; j <= min(k, i); j++) {
            p[i] -= (a[i - j] * c[j]);
        }
    }
    int degq = 0;
    for (int i = 0; i <= k; i++) {
        if (q[i] != 0) degq = i;
    }
    int degp = 0;
    for (int i = 0; i < k; i++) {
        if (p[i] != 0) degp = i;
    }
    cout << degp << "\n";
    REP(0, degp + 1) {
        cout << p[i] << " ";
    }
    cout << "\n";
    cout << degq << "\n";
    REP(0, degq + 1) {
        cout << q[i] << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        
        solve();
    }
    return 0;
}