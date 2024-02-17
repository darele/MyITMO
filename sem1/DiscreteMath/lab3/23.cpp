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

int cero(string &s) {
    int n = s.size();
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '0') return i;
    }
    return -1;
}

int uno(string &s) {
    int n = s.size();
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '1') return i;
    }
    return -1;
}

void solve() {
    string s, copia;
    cin >> s;
    copia = s;
    int n = s.size();
    int unopos = uno(s);
    if (unopos >= 0) {
        s[unopos] = '0';
        for (int i = unopos + 1; i < n; i++) {
            s[i] = '1';
        }
        cout << s << "\n";
        s = copia;
    } else cout  << "-\n";
    int ceropos = cero(s);
    if (ceropos >= 0) {
        s[ceropos] = '1';
        for (int i = ceropos + 1; i < n; i++) {
            s[i] = '0';
        }
        cout << s << "\n";
    } else cout << "-\n";
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