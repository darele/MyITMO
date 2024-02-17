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

vi zfunction(string s) {
    int n = s.size();
    vi z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i < r) {
            z[i] = min(z[i - l], r - i);
        }
        while (s[i + z[i]] == s[z[i]]) {
            z[i]++;
        }
        if (i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

bool ok(int test, vi z) {
    for (int i = test; i < z.size(); i += test) {
        if (z[i] < test) {
            return false;
        }
    }
    return true;
}

void solve() {
    string s;
    cin >> s;
    vi z = zfunction(s);
    vi divisores;
    int n = z.size();
    divisores.reserve(n / 2);
    for (int i = 1; i <= n / 2; i++) {
        if (n % i == 0) {
            divisores.push_back(i);
        }
    }
    for (int i : divisores) {
        if (ok(i, z)) {
            cout << i << "\n";
            return;
        }
    }
    cout << n << "\n";
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