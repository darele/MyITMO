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
vl stpre;
vl stsu;
vl ans;

void init() {
    st.assign(n * 4, 0);
    stpre.assign(n * 4, 0);
    stsu.assign(n * 4, 0);
    ans.assign(n * 4, 0);
}

void setst(int l, int r, int p, int ind, ll value) {
    if (l > ind || r < ind) return;
    if (l == ind && r == ind) {
        st[p] = value;
        stpre[p] = stsu[p] = ans[p] = max(0ll, value);
        return;
    }
    int mid = (l + r) / 2;
    setst(l, mid, p << 1, ind, value);
    setst(mid + 1, r, (p << 1) + 1, ind, value);
    int x, y;
    x = p << 1;
    y = (p << 1) + 1;
    st[p] = st[x] + st[y];
    //lo que originalmente deberia ser
    stpre[p] = stpre[x];
    //ver si se puede extender hacia el prefijo del de la derecha
    stpre[p] = max(stpre[p], st[x] + stpre[y]);
    //Ver si todo el segemento es mejor.
    stpre[p] = max(stpre[p], st[p]);

    //Analogamente se calcula el sufijo
    stsu[p] = stsu[y];
    stsu[p] = max(stsu[p], st[y] + stsu[x]);
    stsu[p] = max(stsu[p], st[p]);

    //Ahora a calcular el mayor
    //Puede ser la respuesta que provee cada uno
    //individualmente;
    ans[p] = max(ans[x], ans[y]);
    //Puede estar entre ellos la respuesta
    ans[p] = max(ans[p], stpre[y] + stsu[x]);
    //Puede ser la suma de ambos
    ans[p] = max(ans[p], st[p]);
    //puede ser el prefijo o el sufijo.
    ans[p] = max(ans[p], stpre[p]);
    ans[p] = max(ans[p], stsu[p]);
}

void setst(int i, ll x) {
    setst(0, n - 1, 1, i, x);
}

ll rsq(int l, int r, int p, int i, int j) {
    if (l >= i && r <= j) return st[p];
    if (l > j || r < i) return 0;
    int mid = (l + r) / 2;
    return rsq(l, mid, p << 1, i, j) + rsq(mid + 1, r, (p << 1) + 1, i, j);
}

ll rsq(int l, int r) {
    return rsq(0, n - 1, 1, l, r);
}

void print() {
    for (int i = 0; i < n; i++) {
        cout << rsq(i, i) << " ";
    }
    cout << endl;
}

void solve()
{
    cin >> n >> m;
    init();
    int x, y;

    for (int i = 0; i < n; i++) {
        cin >> x;
        setst(i, x);
    }
    //print();
    cout << ans[1] << "\n";
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        setst(x, y);
        cout << ans[1] << "\n";
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