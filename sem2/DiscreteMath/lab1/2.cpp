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
#define stringlen 10005

using namespace std;

ifstream fin("problem2.in");
ofstream fout("problem2.out");

int n, m, k;
int terminales[vertices];
string s;
graph grafo;
bool can[stringlen][vertices];

void accept() {
    can[0][1] = 1;
    REP(0, s.size()) {
        REP2(0, n + 5) {
            if (can[i][j]) {
                for (int k = 0; k < grafo[j].size(); k++) {
                    if (grafo[j][k].ff == s[i]) {
                        can[i + 1][grafo[j][k].ss] = 1;
                    }
                }
            }
        }
    }
}

int main() {
    fin >> s;
    fin >> n >> m >> k;
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
    accept();
    REP(0, k) {
        if (can[s.size()][terminales[i]]){
            fout << "Accepts\n";
            return 0;
        }
    }
    fout << "Rejects\n";
    return 0;
}