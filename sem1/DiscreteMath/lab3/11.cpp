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
vi temp;

void imprimir() {
    for (auto x : temp) {
        cout << x << " ";
    }
    cout << "\n";
}

void gen(int i, int ant) {
    imprimir();
    if (i == n) return;
    for (int j = ant + 1; j <= n; j++) {
        temp.push_back(j);
        gen(i + 1, j);
        temp.pop_back();
    }
}

void solve() {
    cin >> n;
    temp.reserve(n);
    gen(0, 0);
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