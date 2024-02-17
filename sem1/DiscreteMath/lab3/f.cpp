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

int n;

bool ok(int a) {
    bool band = false;
    while (a > 0) {
        if (a & 1) {
            if (band) return false;
            band = true;
        }
        else band = false;
        a >>= 1;
    }
    return true;
}

string tobin(int a) {
    int i = n - 1;
    string temp;
    while (i >= 0) {
        if (a & (1 << i)) {
            temp += '1';
        }
        else {
            temp += '0';
        }
        i--;
    }
    return temp;
}

void solve() {

    cin >> n;
    int i = 0;
    vector <string> ans;
    ans.reserve((1 << n));
    while (i < (1 << n)) {
        if (ok(i)) {
            ans.push_back(tobin(i));
        }
        i++;
    }
    cout << ans.size() << "\n";
    for (auto &x : ans) {
        cout << x << "\n";
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