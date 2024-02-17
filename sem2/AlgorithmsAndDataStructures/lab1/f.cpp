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

int n, m;
vl st;
vector <bool> lazy;

void init() {
    st.assign(n * 4, 0);
    lazy.assign(n * 4, false);
    lazy[1] = true;
}

void setst(int l, int r, int p, int i, int j, int v) {
    if (l > j || r < i) return;
    if (l >= i && r <= j) {
        st[p] = v;
        lazy[p] = true;
        return;
    }
    int mid = (l + r) / 2;
    if (lazy[p]) {
        st[p * 2] = st[p * 2 + 1] = st[p];
        lazy[p * 2] = lazy[p * 2 + 1] = true;
        lazy[p] = false;
    }
    setst(l, mid, p << 1, i, j, v);
    setst(mid + 1, r, (p << 1) + 1, i, j, v);
    st[p] = min(st[p << 1], st[(p << 1) + 1]);
}

void setst(int l, int r, int v) {
    setst(0, n - 1, 1, l, r - 1, v);
}

int rmq(int l, int r, int p, int i, int j) {
    if (l > j || r < i) return inf;
    if (l >= i && r <= j) return st[p];
    if (lazy[p]) {
        lazy[p << 1] = lazy[(p << 1) + 1] = true;
        st[p << 1] = st[(p << 1) + 1] = st[p];
        lazy[p << 1] = true;
        lazy[(p << 1) + 1] = true;
        lazy[p] = false;
    }
    int mid = (l + r) / 2;
    int izq = rmq(l, mid, p << 1, i, j);
    int der = rmq(mid + 1, r, (p << 1) + 1, i, j);
    return min(izq, der);
}

int rmq(int l, int r) {
    return rmq(0, n - 1, 1, l, r - 1);
}

void solve() {
    cin >> n >> m;
    init();
    int tipo, l, r, v;
    for (int i = 0; i < m; i++) {
        cin >> tipo >> l >> r;
        if (tipo == 1) {
            cin >> v;
            setst(l, r, v);
        } else {
            cout << rmq(l, r) << "\n";
        }
        /*for (int i = 0; i < n; i++) {
            cout << rmq(i, i + 1) << " ";
        }
        cout << "\n";*/
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