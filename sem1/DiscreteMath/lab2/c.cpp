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

string s;
vector <string> a[2];

bool comp(int a, int b) {
    if (s[a] <= s[b]) {
        if (s[a] == s[b]) return a < b;
        return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> s;
    int n = s.size();
    a[0].resize(n);
    a[1].resize(n);
    vi indices(n);
    REP(0, n) indices[i] = i;
    sort(indices.begin(), indices.end(), comp);
    REP(0, n) {
        REP2(0, n) {
            a[i % 2][j] += s[j];
        }
        REP2(0, n) {
            a[(i + 1) % 2][j] = a[i % 2][indices[j]];
        }
    }
    s = a[n % 2][0];
    REP(0, n) {
        reverse(a[n % 2][i].begin(), a[n % 2][i].end());
        s = min(a[n % 2][i], s);
    }
    cout << s << "\n";
    return 0;
}