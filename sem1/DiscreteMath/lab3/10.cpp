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

vi temp;

void gen(int n, int ant) {
    if (n == 0) {
        int total = temp.size();
        for (int i = 0; i < total - 1; i++) {
            cout << temp[i] << "+";
        }
        cout << temp.back() << "\n";
    }
    for (int i = ant; i <= n; i++) {
        temp.push_back(i);
        gen(n - i, i);
        temp.resize(temp.size() - 1);
    }
}

void solve() {

    int n;
    cin >> n;
    temp.reserve(n);
    gen(n, 1);
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