#include <bits/stdc++.h>
#define DBG(x) cerr << #x << "=" << (x) << "\n"
#define RAYA cerr << "======================\n"
#define ll long long
#define ii pair <int, int>
#define dl pair <ll, ll>
#define vi vector <int>
#define vl vector <ll>
#define vii vector <ii>
#define graph vector <vii>
#define ff first
#define ss second
#define REP(a, b) for (int i = a; i < b; i++)
#define REP2(a, b) for (int j = a; j < b; j++)
#define REPS(a, b, c) for (int i = a; i < b; i += c)
#define vertices 105
#define stringlen 1005
#define mod 1000000007

using namespace std;

ifstream fin("problem4.in");
ofstream fout("problem4.out");

int n, m, k, l;
int terminales[vertices];
ll dp[stringlen][vertices];
graph grafo;

int main() {

    fin >> n >> m >> k >> l;
    grafo.assign(n + 5, vii());
    REP(0, k) {
        fin >> terminales[i];
    }
    int in1, in2;
    char in3;
    REP(0, m) {
        fin >> in1 >> in2 >> in3;
        grafo[in1].push_back({in3, in2});
    }
    dp[0][1] = 1;
    REP(0, l) {
        REP2(0, n + 1) {
            for (int k = 0; k < grafo[j].size(); k++) {
                ii v = grafo[j][k];
                if (dp[i][j] > 0) {
                    dp[i + 1][v.ss] += dp[i][j];
                    dp[i + 1][v.ss] %= mod;
                }
            }
        }
    }
    ll ans = 0;
    REP(0, k) {
        ans += dp[l][terminales[i]];
        ans %= mod;
    }
    fout << ans << "\n";
    return 0;
}