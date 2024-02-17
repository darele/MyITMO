#include <bits/stdc++.h>
#define DBG(x) cerr << #x << "=" << (x) << "\n"
#define RAYA cerr << "======================\n"
#define ll long long
#define ii pair<int, int>
#define dl pair<ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define vii vector<ii>
#define graph vector<vi>
#define ff first
#define ss second
#define REP(a, b) for (int i = a; i < b; i++)
#define REP2(a, b) for (int j = a; j < b; j++)
#define REPS(a, b, c) for (int i = a; i < b; i += c)
#define inf 1000000007

using namespace std;

ll n, m;
vl st;

void init() {
    st.assign(n * 4, 0);
    
}

void setst(int l, int r, int p, int ind, ll value) {
    if (l > ind || r < ind) return;
    if (l == ind && r == ind) {
        st[p] = value;
        return;
    }
    int mid = (l + r) / 2;
    setst(l, mid, p << 1, ind, value);
    setst(mid + 1, r, (p << 1) + 1, ind, value);
    st[p] = max(st[p << 1], st[(p << 1) + 1]);
}

void setst(int i, ll x) {
    setst(0, n - 1, 1, i, x);
}

ll rsq(int l, int r, int p, int x, int i) {
    if (r < i) return inf;
    if (st[p] < x) return inf;
    if (l == r) return l;
    int mid = (l + r) / 2;
    int izq, der;
    izq = rsq(l, mid, p << 1, x, i);
    der = rsq(mid + 1, r, (p << 1) + 1, x, i);
    return min(izq, der);
}

ll rsq(int x, int l) {
    return rsq(0, n - 1, 1, x, l);
}

/*void print() {
    for (int i = 0; i < n; i++) {
        cout << rsq(-1, i) << " ";
    }
    cout << endl;
}*/

void solve()
{
    cin >> n >> m;
    init();
    int tipo, x, y;

    for (int i = 0; i < n; i++) {
        cin >> x;
        setst(i, x);
    }
    //print();
    for (int i = 0; i < m; i++) {
        cin >> tipo >> x >> y;
        if (tipo == 1) {
            setst(x, y);
        } else {
            int temp = rsq(x, y);
            cout << (temp == inf ? -1 : temp) << "\n";
            //print();
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}