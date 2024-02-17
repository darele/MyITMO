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
    int n;
    cin >> n;
    vi arr(n);
    REP(0, n) cin >> arr[i];
    ii ans[n];
    REP(0, n) {
        ans[i] = {1, -1};
        for (int j = i - 1; j >= 0; j--) {
            if (arr[j] < arr[i] && ans[j].ff >= ans[i].ff) {
                ans[i].ff = ans[j].ff + 1;
                ans[i].ss = j;
            }
        }
    }
    int mayor = 0;
    int indice = 0;
    for (int i = 0; i < n; i++) {
        if (ans[i].ff > mayor) {
            mayor = ans[i].ff;
            indice = i;
        }
    }
    cout << mayor << "\n";
    vi res;
    res.reserve(mayor);
    while (indice != -1) {
        res.push_back(indice);
        indice = ans[indice].ss;
    }
    reverse(res.begin(), res.end());
    for (auto x : res) cout << arr[x] << " ";
    cout << "\n";
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