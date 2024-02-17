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
#define tam 400005

using namespace std;

vi p, ans, r;
int grupo[tam];
int sumgrupo[tam];
int nodo;

void init(int n) {
    p.resize(n + 5);
    r.assign(n + 5, 0);
    nodo = n + 1;
    REP(0, n + 5) {
        grupo[]
        p[i] = i;
    }
}

int findset(int u) {
    if (p[u] == p[u]) return p[u];
    sumgrupo[u] += sumgrupo[grupo[p[u]]];
    return p[u] = findset(p[u]);
}

void merge(int u, int v) {
    u = findset(u);
    v = findset(v);
    if (u == v) return;
    nodo++;
    if (r[u] >= r[v]) {
        if (r[u] == r[v]) r[u]++;
        p[v] = u;
        grupo[u] = nodo;
    } else {
        p[u] = v;
        grupo[v] = nodo;
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    init(n);
    string s;
    int in1, in2;
    while (m--) {
        cin >> s;
        if (s == "join") {
            cin >> in1 >> in2;
            merge(in1, in2);
        } else if (s == "add") {
            cin >> in1 >> in2;
            ans[findset(in1)] += in2;
        } else  {
            cin >> in1;
            int temp = findset(in1);
            cout << ans[temp] + ans[in1] << "\n";
        }
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