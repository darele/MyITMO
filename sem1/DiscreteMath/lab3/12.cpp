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

vector <vector <int> > ans;
vector <bool> vis;

void gen(int n, int k, int ant, int &x, int &y) {
    if (n == x && k == y) {
        for (int i = 0; i < y; i++) {
            for (int j = 0; j < ans[i].size(); j++) {
                cout << ans[i][j] + 1 << " ";
            }
            cout << "\n";
        }
        cout << "\n";
        return;
    }
    if (n == x) return;
    if (k == y) return;
    for (int i = ant + 1; i < x; i++) {
        if (vis[i]) continue;
        ans[k].push_back(i);
        vis[i] = 1;
        gen(n + 1, k + 1, -1, x, y);
        gen(n + 1, k, i, x, y);
        vis[i] = 0;
        ans[k].pop_back();
        if (ans[k].size() == 0) return;
    }
}

void solve() {
    int n, k;
    cin >> n >> k;
    ans.resize(k + 5);
    for (int i = 0; i < k + 5; i++) ans[i].reserve(n + 5);
    vis.assign(n + 5, 0);
    gen(0, 0, -1, n, k);
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