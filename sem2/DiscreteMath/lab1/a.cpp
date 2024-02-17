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
#define tam 100005

using namespace std;

ifstream fin("problem1.in");
ofstream fout("problem1.out");

int n, m, k;
int terminales[tam];
int longitud[tam];
string s;
graph grafo;

void bfs() {
    queue <int> q;
    q.push(1);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        REP(0, grafo[u].size()) {
            ii v = grafo[u][i];
            if (v.ff == s[longitud[u]]) {
                longitud[v.ss] = longitud[u] + 1;
                q.push(v.ss);
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
    bfs();
    REP(0, k) {
        if (longitud[terminales[i]] == s.size()) {
            fout << "Accepts\n";
            return 0;
        }
    }
    fout << "Rejects\n";
    return 0;
}