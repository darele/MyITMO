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
#define tam 55

using namespace std;

ll d[tam][tam];

void gen() {
    d[0][0] = 1;
    for (int i = 1; i < tam; i++) {
        for (int j = 0; j < tam - 1; j++) {
            d[i][j] = (j > 0 ? d[i - 1][j - 1] : 0) + d[i - 1][j + 1];
        }
    }
}

void solve() {
    ll n, k;
    cin >> n >> k;
    k++;
    gen();
    int depth = 0;
    string ans = "";
    int shift;
    ll temp;
    stack <char> pila;
    for (int i = 0; i < 2 * n; i++) {
        shift = ((2 * n - i - 1 - depth - 1) / 2);
        if (shift >= 0 && depth + 1 <= n) {
            temp = d[2 * n - i - 1][depth + 1] << shift;
            if (temp >= k) {
                ans += '(';
                pila.push('(');
                depth++;
                continue;
            }
            k -= temp;
        }

        shift = ((2 * n - i - 1 - depth + 1) / 2);
        if (shift >= 0 && depth && pila.top() == '(') {
            temp = d[2*n-i-1][depth-1] << shift;
            if (temp >= k) {
                ans += ')';
                pila.pop();
                depth--;
                continue;
            }
            k -= temp;
        }

        shift = ((2*n-i-1-depth-1) / 2);
        if (shift >= 0 && depth + 1 <= n) {
            temp = d[2*n-i-1][depth+1] << shift;
            if (temp >= k) {
                ans += '[';
                pila.push('[');
                depth++;
                continue;
            }
            k -= temp;
        }

        ans += ']';
        pila.pop();
        depth--;
    }
    cout << ans << "\n";
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