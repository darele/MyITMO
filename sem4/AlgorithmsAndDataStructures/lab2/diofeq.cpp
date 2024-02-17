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

void solve() {
    ll num1, num2, mod, s1, s2, lim1, lim2;
    num1 = 17;
    num2 = 22;
    mod = 404;
    s1 = 1;
    s2 = 1;
    lim1 = 10000;
    lim2 = 10000;
    int cont = 0;
    //Probar todas las soluciones
    for (ll i = 0; i < lim1; i++) {
        for (ll j = 0; j < lim2; j++) {
            if (num1 * i + num2 * j == mod) {
                cout << i << " " << j << endl;
                cont++;
            }
        }
    }
    cout << cont << endl;
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