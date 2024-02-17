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
    int n;
    cin >> n;
    vector <string> v;
    string temp;
    REP(0, n) temp += "0";
    v.push_back(temp);
    set <string> s;
    s.insert(temp);
    while (1) {
        reverse(temp.begin(), temp.end());
        temp.pop_back();
        reverse(temp.begin(), temp.end());
        temp += "1";
        if (s.find(temp) == s.end()) {
            s.insert(temp);
            v.push_back(temp);
        } else {
            temp[temp.size() - 1] = '0';
            if (s.find(temp) == s.end()) {
                s.insert(temp);
                v.push_back(temp);
            } else {
                break;
            }
        }
    }
    for (auto i : v) {
        cout << i << "\n";
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