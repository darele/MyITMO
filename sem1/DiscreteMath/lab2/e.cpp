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
 
int buscar(vector <string> &dic, vi &values, string s) {
    int n = s.size();
    REP(0, dic.size()) {
        if (dic[i] == s) return values[i];
    }
    return -1;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    string s;
    cin >> s;
    int n = s.size();
    vector <bool> used(256, false);
    REP(0, s.size()) {
        if (!used[s[i]]) {
            used[s[i]] = true;
        }
    }
    vector <string> dic;
    vi values;
    values.reserve(n * n);
    dic.reserve(n * n);
    REP('a', 'z' + 1) {
        if (used[i]) {
            dic.push_back(string(1, i));
            values.push_back(i - 'a');
        }
    }
    string P = "";
    int j = 26;
    REP(0, n) {
        if (buscar(dic, values, P + s[i]) != -1) {
            P += s[i];
        } else {
            dic.push_back(P + s[i]);
            values.push_back(j++);
            cout << buscar(dic, values, P) << " ";
            P = string(1, s[i]);
        }
    }
    cout << buscar(dic, values, P) << "\n";
    return 0;
}