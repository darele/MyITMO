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

int n, k;
vi temp;
vector <bool> vis;

void gen(int i) {
    if (i == n + 1) {
        k--;
        if (k == -1) {
            for (int x : temp) {
                cout << x << " ";
            }
            cout << "\n";
        } 
        return;
    }
    for (int j = 1; j <= n; j++) {
        if (!vis[j]) {
            vis[j] = true;
            temp.push_back(j);
            gen(i + 1);
            temp.pop_back();
            vis[j] = false;
        }
    }
}

void solve() {
    cin >> n >> k;
    vis.assign(n + 1, false);
    gen(1);
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