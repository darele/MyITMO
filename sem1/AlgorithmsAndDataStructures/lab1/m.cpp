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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, k;
    cin >> n >> k;
    vl a(n);
    ll x, y, z;
    REP(0, n) {
        cin >> a[i];
    }
    REP(0, k) {
        cin >> z;
        x = upper_bound(a.begin(), a.end(), z) - a.begin();
        if (x > 0) y = x - 1;
        else y = x;
        if (abs(a[x] - z) < abs(z - a[y])) {
            cout << a[x] << "\n";
        } else {
            cout << a[y] << "\n";
        }
    }
    return 0;
}