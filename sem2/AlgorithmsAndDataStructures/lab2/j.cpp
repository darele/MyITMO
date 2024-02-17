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
#define tam 1005

using namespace std;

int dp[tam][tam];
int mat[tam][tam];
int n, m;

void solve() {
    cin >> n >> m;
    REP(1, n + 1) {
        REP2(1, m + 1) {
            cin >> mat[i][j];
        }
    }
    int mayor = 0;
    REP(1, n + 1) {
        REP2(1, m + 1) {
            if (mat[i][j]) {
                dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
                mayor = max(mayor, dp[i][j]);
            }
        }
    }
    cout << mayor << "\n";
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