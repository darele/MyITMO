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
#define lim 4010
#define mod 998244353
 
using namespace std;
 
ll p[lim];
ll q[lim];
ll divi[lim];
ll ans[lim];
 
ll c(int n) {
    ll tempans = 0;
    for (int i = 0; i <= n && n - i >= 0; i++) {
        tempans += ((p[i] * q[n - i]) % mod);
        tempans %= mod;
    }
    return tempans;
}
 
ll d(int n) {
    ll tempans = p[n];
    for (int i = 0; i <= n - 1 && n - i >= 0; i++) {
        tempans = (tempans + mod - ((divi[i] * q[n - i]) % mod)) % mod;
    }
    return divi[n] = tempans;
}
 
void printans(int anssize) {
    cout << anssize << "\n";
    REP(0, anssize + 1) {
        cout << ans[i] << " ";
    }
    cout << "\n";
    REP(0, lim) {
        ans[i] = 0;
    }
}
 
void solve() {
    int n, m;
    cin >> n >> m;
    REP(0, n + 1) {
        cin >> p[i];
    }
    REP(0, m + 1) {
        cin >> q[i];
    }
    int anssize = 0;
    REP(0, min(n, m) + 1) {
        ans[i] = (p[i] + q[i]) % mod;
        if (p[i] + q[i] != 0) anssize = i;
    }
    REP(min(n, m) + 1, max(n, m) + 1) {
        ans[i] = (p[i] + q[i]) % mod;
        if (p[i] + q[i] != 0) anssize = i;
    }
    printans(anssize);
    anssize = 0;
    REP(0, n + m + 1) {
        ans[i] = c(i);
        if (ans[i] != 0) anssize = i;
    }
    printans(anssize);
    REP(0, 1000) {
        cout << d(i) << " ";
    }
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