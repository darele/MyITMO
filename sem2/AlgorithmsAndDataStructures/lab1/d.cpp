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

using namespace std;

ll n, m;
vl st;

void init() {
    st.assign(n * 4, 0);
    
}

void setst(int l, int r, int p, int ind) {
    if (l > ind || r < ind) return;
    if (l == ind && r == ind) {
        st[p] = (st[p] ? 0 : 1);
        return;
    }
    int mid = (l + r) / 2;
    setst(l, mid, p << 1, ind);
    setst(mid + 1, r, (p << 1) + 1, ind);
    st[p] = st[p << 1] + st[(p << 1) + 1];
}

void setst(int i) {
    setst(0, n - 1, 1, i);
}

ll rsq(int l, int r, int p, int k) {
    if (l == r) return l;
    int mid = (l + r) / 2;
    if (st[p << 1] < k) {
        return rsq(mid + 1, r, (p << 1) + 1, k - st[p << 1]);
    } else {
        return rsq(l, mid, p << 1, k);
    }
}

ll rsq(int k) {
    return rsq(0, n - 1, 1, k);
}

ll rsq(int l, int r, int p, int i, int j) {
    if (l > j || r < i) return 0;
    if (l == r) return st[p];
    int mid = (l + r) / 2;
    return rsq(l, mid, p << 1, i, j) + rsq(mid + 1, r, (p << 1) + 1, i, j);
}

ll rsq(int l, int r) {
    return rsq(0, n - 1, 1, l, r);
}

void solve()
{
    cin >> n >> m;
    init();
    int tipo, x;

    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x) setst(i);
    }
    for (int i = 0; i < m; i++) {
        cin >> tipo >> x;
        if (tipo == 1) {
            setst(x);
        } else {
            cout << rsq(x + 1) << "\n";
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