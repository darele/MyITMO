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

int n;
stack <int> pila;
vector <char> v;
int unos;

void gen(int i) {
    if (i == 2 * n) {
        for (char i : v) {
            if (i == '1') {
                cout << "(";
            } else {
                cout << ")";
            }
        }
        cout << "\n";
        return;
    }
    if (unos < n) {
        unos++;
        v[i] = '1';
        pila.push(0);
        gen(i + 1);
        pila.pop();
        unos--;
    }
    if (pila.size()) {
        pila.pop();
        v[i] = '0';
        gen(i + 1);
        pila.push(0);
    }
}

void solve() {
    cin >> n;
    v.resize(n * 2);
    gen(0);
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