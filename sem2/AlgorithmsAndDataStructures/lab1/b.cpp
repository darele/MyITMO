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
#define inf 1e9 + 5

using namespace std;

ll n, m;
vii st;

void print() {
    int tam = 1;
    int x = 0;
    for (int i = 1; i < st.size(); i++) {
        cout << st[i].ff << " " << st[i].ss << "; ";
        x++;
        if (x == tam) {
            x = 0;
            tam *= 2;
            cout << endl;
        }
    }
}

void init() {
    st.assign(n * 4, {inf, 0});
    
}

void setst(int l, int r, int p, int ind, int value) {
    if (l > ind || r < ind) return;
    if (l == ind && r == ind) {
        st[p] = {value, 1};
        return;
    }
    int mid = (l + r) / 2;
    setst(l, mid, p << 1, ind, value);
    setst(mid + 1, r, (p << 1) + 1, ind, value);
    ii der = st[p << 1];
    ii izq = st[(p << 1) + 1];
    ii ans;
    if (der.ff <= izq.ff) {
        ans = der;
        if (der.ff == izq.ff) ans.second += izq.ss;
    } else {
        ans = izq;
    }
    st[p] = ans;
}

void setst(int i, int x) {
    setst(0, n - 1, 1, i, x);
}

ii rmq(int l, int r, int p, int i, int j) {
    if (l >= i && r <= j) return st[p];
    if (l > j || r < i) return {inf, 0};
    int mid = (l + r) / 2;
    ii der = rmq(l, mid, p << 1, i, j);
    ii izq = rmq(mid + 1, r, (p << 1) + 1, i, j);
    ii ans;
    if (der.ff <= izq.ff) {
        ans = der;
        if (der.ff == izq.ff) {
            ans.ss += izq.ss;
        }
    } else {
        ans = izq;
    }
    return ans;
}

ii rmq(int l, int r) {
    return rmq(0, n - 1, 1, l, r);
}

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
            ii ans = rmq(x, y - 1);
            cout << ans.ff << " " << ans.ss << "\n";
        }
        //print();
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