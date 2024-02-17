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
    int n, k;
    cin >> n >> k;
    int a[k];
    int b[k + 1];
    for (int i = 0; i < k; i++) {
        cin >> a[i];
    }
    REP(0, k) b[i] = a[i];
    b[k] = n + 1;
    int i = k - 1;
    while (i >= 0 && b[i + 1] - b[i] < 2) {
        i--;
    }
    if (i == -1) {
        cout << "-1\n";
        return;
    }
    b[i]++;
    for (int j = i + 1; j < k; j++) {
        b[j] = b[j - 1] + 1;
    }
    for (i = 0; i < k; i++) a[i] = b[i];
    for (int x : a) cout << x << " ";
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