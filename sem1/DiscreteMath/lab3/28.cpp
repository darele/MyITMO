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
    int b[n];
    REP(0, n) cin >> b[i];
    int i = n - 2;
    while (i >= 0 and b[i] >= b[i + 1]) i--;
    if (i >= 0) {
        int j = i + 1;
        while (j < n - 1 && b[j + 1] > b[i]) j++;
        swap(b[i], b[j]);
        reverse(b + i + 1, b + n);
        REP(0, n) cout << b[i] << " ";
        cout << "\n";
    } else {
        REP(0, n) cout << "0 ";
        cout << "\n";
    }
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