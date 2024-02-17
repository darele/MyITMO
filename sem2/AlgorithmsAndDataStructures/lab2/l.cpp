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
    ll k, b, m;
    cin >> n;
    ll arr[n];
    cin >> arr[0];
    cin >> k >> b >> m;
    REP(1, n) arr[i] = (k * arr[i - 1] + b) % m;
    vi ans;
    ans.reserve(n);
    ans.push_back(arr[0]);
    for (int i = 1; i < n; i++) {
        if (arr[i] < ans[0]) {
            ans[0] = arr[i];
        } else if (arr[i] > ans[ans.size() - 1]) {
            ans.push_back(arr[i]);
        } else {
            int r = upper_bound(ans.begin(), ans.end(), arr[i]) - ans.begin();
            ans[r] = arr[i];
        }
    }
    cout << ans.size() << "\n";
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