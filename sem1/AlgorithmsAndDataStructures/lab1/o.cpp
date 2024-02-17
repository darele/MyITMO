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

bool ok(long double x, long double c) {
    return x * x + sqrt(x) <= c;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    long double c;
    cin >> c;
    long double ini, fin, mid;
    ini = 0;
    fin = c;
    mid = (ini + fin) / 2;
    while (fin - ini > 0.0000001) {
        mid = (ini + fin) / 2;
        if (ok(mid, c)) {
            ini = mid;
        } else {
            fin = mid;
        }
    }
    cout << fixed << setprecision(6) << mid << "\n";
    return 0;
}