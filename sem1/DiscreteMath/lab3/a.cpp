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

string binary(int num, int n) {
    string s = "";
    while (num) {
        s += (num % 2 ? '1' : '0');
        num /= 2;
    }
    while (s.size() < n) s += '0';
    reverse(s.begin(), s.end());
    return s;
}

void solve() {
    int n;
    cin >> n;
    int lim = (1 << n);
    for (int i = 0; i < lim; i++) {
        cout << binary(i, n) << "\n";
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