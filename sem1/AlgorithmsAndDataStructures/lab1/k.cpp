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
#define inf 1000000005

using namespace std;

vi p, a;

void init(int n) {
    p.resize(n);
    REP(0, n) p[i] = i;
}

int findset(int u) {return p[u] == u ? u : p[u] = findset(p[u]);}

int unionset(int u, int v) {
    u = findset(u);
    v = findset(v);
    if (u == v) return u;
    p[u] = v;
    return u;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int q;
    cin >> q;
    init(q);
    a.reserve(q);
    stack <int> anteriores;
    char x;
    int i = 0;
    int ini = 0;
    int j = 0;
    while (q--) {
        cin >> x;
        if (x == '+') {
            cin >> a[i];
            while (anteriores.size() && a[anteriores.top()] >= a[i]) {
                j = anteriores.top();
                anteriores.pop();
                unionset(j, i);
            }
            anteriores.push(i);
            i++;
            cout << a[findset(ini)] << "\n";
        } else {
            ++ini;
            cout << (ini < i ? a[findset(ini)] : -1) << "\n";
        }
    }
    return 0;
}