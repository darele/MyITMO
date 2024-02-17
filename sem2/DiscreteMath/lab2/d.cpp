#include <string>
#include <bits/stdc++.h>
#define DBG(x) cerr << #x << "=" << (x) << "\n"
#define RAYA cerr << "======================\n"
#define ll long long
#define ii pair <int, int>
#define dl pair <ll, ll>
#define vi vector <int>
#define vl vector <ll>
#define vii vector <ii>
#define graph vector <vector <string> >
#define ff first
#define ss second
#define REP(a, b) for (int i = a; i < b; i++)
#define REP2(a, b) for (int j = a; j < b; j++)
#define REPS(a, b, c) for (int i = a; i < b; i += c)
#define tam 105
#define mod 1000000007

using namespace std;

ifstream fin("nfc.in");
ofstream fout("nfc.out");

graph grafo;
ll dp[256][tam][tam];

int main() {

    grafo.assign(256, vector <string> ());
    int n;
    fin >> n;
    char st;
    fin >> st;
    string s;
    getline(fin, s);
    REP(0, n) {
        getline(fin, s);
        grafo[s[0]].push_back(s.substr(5));
    }
    string pal;
    getline(fin, pal);
    REP2(0, pal.size()) {
        REP('A', 'Z' + 1) {
            for (string s : grafo[i]) {
                if (s[0] == pal[j]) {
                    dp[i][j][j] = 1;
                }
            }
        }
    }
    for (int x = 'A'; x <= 'Z'; x++) {
        for (int y = 0; y < grafo[x].size(); y++) {
            if (grafo[x][y].size() < 2) continue;
            for (int i = 0; i < pal.size(); i++) {
                for (int j = i; j < pal.size(); j++) {
                    for (int k = i; k < j; k++) {
                        dp[x][i][j] += ((dp[grafo[x][y][0]][i][k] * dp[grafo[x][y][1]][k + 1][j]) % mod);
                        dp[x][i][j] %= mod;
                    }
                }
            }
        }
    }
    fout << dp[st][0][pal.size() - 1] << "\n";
    return 0;
}