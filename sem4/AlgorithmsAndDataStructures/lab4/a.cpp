#include <bits/stdc++.h>
#define DBG(x) cerr << #x << "=" << (x) << "\n"
#define RAYA cerr << "======================\n"
#define ll uint64_t
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

void normalize(vl &a, vl &b) {
    int n = max(a.size(), b.size());
    int potencia_cercana = 1;
    while (potencia_cercana < n) {
        potencia_cercana <<= 1;
    }
    n = potencia_cercana;
    a.reserve(n);
    b.reserve(n);
    while (a.size() < n) {
        a.push_back(0);
    }
    while (b.size() < n) {
        b.push_back(0);
    }
}

// vl mul(vl &a, vl &b, vl &c, int ini, int n) {
//     if ()
// }

string mul(vl &a, vl &b) {
    normalize(a, b);
    int n = a.size();
    vl c(2 * n);
    // vl temp = mul(a, b, c, 0, n);
    // string ans(n, '0');
    // for (int i = 0; i < n; i++) {
    //     ans[i] = temp[i];
    // }
    return "";
}

uint64_t substring(string s, int ini, int n) {
    uint64_t ans = 0;
    for (int i = ini; i < s.size() && i < ini + n; i++) {
        ans *= 10;
        ans += s[i];
    }
    return ans;
}

vl parse(string s) {
    vl ans;
    if (s[0] == '-') {
        s[0] = '0';
    }
    REP(0, s.size()) {
        s[i] -= '0';
    }
    int base = 9;
    ans.assign((s.size() + base - 1) / base , 0);
    int index = 0;
    for (int i = 0; i < s.size(); i += base) {
        ans[index++] = substring(s, i, base);
    }
    for (int i = 0; i < index; i++) {
        cout << ans[i] << endl;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

void solve() {
    string a, b;
    cin >> a >> b;
    vl num1 = parse(a);
    vl num2 = parse(b);
    int signo = 1;
    if (a[0] == '-') {
        signo *= -1;
    }
    if (b[0] == '-') {
        signo *= -1;
    }
    cout << (signo == -1 ? "-" : "") << mul(num1, num2) << "\n";
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