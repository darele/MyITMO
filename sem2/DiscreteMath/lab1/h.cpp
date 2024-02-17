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
#define vertices 50005
#define LOG 20

using namespace std;

ifstream fin("minimization.in");
ofstream fout("minimization.out");

int n, m, k;
graph grafo;
vi grafo_prime[vertices][256];
int terminales[vertices];
bitset <vertices> esterminal;
bitset <vertices> reachable;
bitset <vertices> marked[vertices];
int component[vertices];

void build_table() {
    queue <ii> q;
    REP(1, n + 1) {
        REP2(1, n + 1) {
            if (!marked[i][j] && esterminal[i] != esterminal[j]) {
                marked[i][j] = marked[j][i] = 1;
                q.push({i, j});
            }
        }
    }
    while (!q.empty()) {
        ii u = q.front();
        q.pop();
        for (int c = 'a'; c <= 'z'; c++) {
            for (int r : grafo_prime[u.ff][c]) {
                for (int s : grafo_prime[u.ss][c]) {
                    if (!marked[r][s]) {
                        marked[r][s] = marked[s][r] = 1;
                        q.push({r, s});
                    }
                }
            }
        }
    }
}

void get_reachable(int u) {
    if (reachable[u]) return;
    reachable[u] = true;
    REP('a', 'z' + 1) {
        int v = grafo[u][i];
        if (v != 0) {;
            get_reachable(v);
        }
    }
}

int main() {

    fin >> n >> m >> k;
    grafo.assign(n + 5, vi(256, 0));
    REP(0, k) {
        fin >> terminales[i];
        esterminal[terminales[i]] = 1;
    }
    int in1, in2;
    char in3;
    REP(0, m) {
        fin >> in1 >> in2 >> in3;
        grafo[in1][in3] = in2;
        grafo_prime[in2][in3].push_back(in1);
    }

    get_reachable(1);
    build_table();
    REP(1, n + 1) {
        if (!marked[0][i]) component[i] = 0;
    }
    int componentcount = 0;
    REP(1, n + 1) {
        if (!reachable[i]) continue;
        if (component[i] == 0) {
            componentcount++;
            component[i] = componentcount;
            for (int j = i + 1; j <= n; j++) {
                if (!marked[i][j]) {
                    component[j] = componentcount;
                }
            }
        }
    }
    graph ans;
    ans.assign(n + 5, vi(256, 0));
    set <int> nuevosterminales;
    REP(0, k) {
        nuevosterminales.insert(component[terminales[i]]);
    }
    int nuevasaristas = 0;
    REP(1, n + 1) {
        for (int c = 'a'; c <= 'z'; c++) {
            int v = grafo[i][c];
            if (v != 0) {
                if (ans[component[i]][c] == 0) {
                    ans[component[i]][c] = component[v];
                    nuevasaristas++;
                }
            }
        }
    }
    fout << componentcount << " " << nuevasaristas << " " << nuevosterminales.size() << "\n";
    for (int i : nuevosterminales) {
        fout << i << " ";
    }
    fout << "\n";
    REP (1, componentcount + 1) {
        for (int c = 'a'; c <= 'z'; c++) {
            int j = ans[i][c];
            if (j != 0) {
                fout << i << " " << j << " " << (char)c << "\n";
            }
        }
    }
    return 0;
}