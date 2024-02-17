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

vector <int> compute(string s) {
    int n = s.size();
    vi p(n);
    p[0] = 0;
    for (int i = 1; i < n; i++) {
        int j = p[i - 1];
        while (j > 0 && s[i] != s[j]) {
            j = p[j - 1];
        }
        if (s[i] == s[j]) {
            j++;
        }
        p[i] = j;
    }
    return p;
}

void solve() {
    string p, t;
    cin >> p >> t;
    string temp = p + "$" + t;
    int des = p.size();
    vi ans = compute(temp);
    vi answers;
    answers.reserve(p.size());
    for (int i = des - 1; i < temp.size(); i++) {
        if (ans[i] == p.size()) {
            answers.push_back(i - 2 * des + 1);
        }
    }
    cout << answers.size() << "\n";
    for (int i : answers) {
        cout << i << " ";
    }
    cout << endl;
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