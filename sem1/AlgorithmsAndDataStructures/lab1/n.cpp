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

long long n, x, y;

ll copia1(ll k) {
    return k / x;
}

ll copia2(ll k) {
    return k / y;
}

bool ok(ll k) {
    return copia1(k) + copia2(k) >= n;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> x >> y;
    long long ans = 0;
    long long menor = min(x, y);
    if (n == 1) {
        cout << menor << "\n";
        return 0;
    }
    n--;
    ll ini, fin, mid;
    ini = 0, fin = n * menor;
    mid = (ini + fin) / 2;
    while (fin >= ini) {
        mid = (ini + fin) / 2;
        if (ok(mid)) fin = mid - 1;
        else ini = mid + 1;
    }
    if (ok(mid - 1)) ans = mid - 1;
    else if (ok(mid)) ans = mid;
    else ans = mid + 1;
    cout << ans + menor << "\n";
    return 0;
}