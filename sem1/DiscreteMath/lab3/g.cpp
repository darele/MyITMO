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
vector <bool> vis;
vi ans;

void per(int i) {
    if (i == n) {
        for (int x : ans) {
            cout << x << " ";
        }
        cout << "\n";
        return;
    }
    for (int j = 1; j <= n; j++) {
        if (vis[j]) continue;
        ans[i] = j;
        vis[j] = true;
        per(i + 1);
        vis[j] = false;
    }
}

void solve() {
    cin >> n;
    vis.assign(n + 1, false);
    ans.resize(n);
    per(0);
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