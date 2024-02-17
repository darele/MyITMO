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
    string s;
    cin >> s;
    int n = s.size();
    int bal[n + 1];
    bal[0] = 0;
    REP(0, n) {
        bal[i + 1] = bal[i];
        if (s[i] == '(') {
            bal[i + 1] += 1;
        }
        else bal[i + 1] -= 1;
    }
    int i;
    int lim = n / 2;
    for (i = n; i > 0; i--) {
        if (s[i - 1] == '(' && bal[i] > 1) {
            break;
        }
    }
    if (i == 0) {
        cout << "-\n";
        return;
    }
    i--;
    s[i] = ')';
    int cont = 0;
    for (int j = 0; j < i; j++) {
        if (s[j] == '(') cont++;
    }
    for (i++; i < n; i++) {
        if (cont < lim) {
            s[i] = '(';
            cont++;
        }
        else {
            s[i] = ')';
        }
    }
    cout << s << "\n";
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