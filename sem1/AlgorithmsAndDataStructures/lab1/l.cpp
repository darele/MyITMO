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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vi a(n);
    REP(0, n) cin >> a[i];
    sort(a.begin(), a.end());
    int q;
    cin >> q;
    REP(0, q) {
        int l, r;
        cin >> l >> r;
        int y = upper_bound(a.begin(), a.end(), r) - a.begin();
        int x = upper_bound(a.begin(), a.end(), l - 1) - a.begin();
        cout << y - x << " ";
    }
    cout << "\n";
    return 0;
}