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

    vector <pair <string, int> > v;
    int n;
    string s, temp;
    int level = 0;
    cin >> n;
    REP(0, n) {
        cin >> s;
        level = 0;
        REP2(0, (int)s.size()) {
            if (s[j] == '/') {
                level += 2;
            }
        }
        v.push_back({s, level});
    }
    sort(v.begin(), v.end());
    REP(0, n) {
        REP2(0, v[i].ss) cout << " ";
        REP2(0, v[i].ff.size()) {
            if (v[i].ff[j] == '/') {
                temp = "";
            } else {
                temp += v[i].ff[j];
            }
        }
        cout << temp << "\n";
    }
    return 0;
}