#include <bits/stdc++.h>
#define DBG(x) cerr << #x << "=" << (x) << "\n"
#define RAYA cerr << "======================\n"
#define ll long long
#define ii pair <int, int>
#define dl pair <ll, ll>
#define lll pair <ll, ii>
#define vi vector <int>
#define vl vector <ll>
#define vii vector <ii>
#define graph vector <vi>
#define ff first
#define ss second
#define REP(a, b) for (int i = a; i < b; i++)
#define REP2(a, b) for (int j = a; j < b; j++)
#define REPS(a, b, c) for (int i = a; i < b; i += c)
#define tam 1010ll

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int n, m;
ll mat[tam][tam];
lll dp[tam][tam];

int main() {

    fin >> n >> m;
    REP(0, n) {
        REP2(0, m) {
            fin >> mat[i][j];
            dp[i][j].ff = -1ll*(tam*tam*100);
        }
    }
    dp[0][0] = {mat[0][0], {0, 0}};
    REP(0, n) {
        REP2(0, m) {
            if (j > 0 && dp[i][j - 1].ff + mat[i][j] > dp[i][j].ff) {
                dp[i][j] = {dp[i][j - 1].ff + mat[i][j], {i, j - 1}};
            }
            if (i > 0 && dp[i - 1][j].ff + mat[i][j] > dp[i][j].ff) {
                dp[i][j] = {dp[i - 1][j].ff + mat[i][j], {i - 1, j}};
            }
        }
    }
    fout << dp[n - 1][m - 1].ff << "\n";
    ii actual = {n - 1, m - 1};
    vector <string> ans;
    ans.reserve(n + m);
    while (actual.ff > 0 || actual.ss > 0) {
        ii temp = dp[actual.ff][actual.ss].ss;
        if (actual.ff == temp.ff) ans.push_back("R");
        else ans.push_back("D");
        actual = temp;
    }
    reverse(ans.begin(), ans.end());
    for (auto i : ans) {
        fout << i;
    }
    fout << "\n";
    return 0;
}