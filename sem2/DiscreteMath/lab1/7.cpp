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
#define vertices 1005

using namespace std;

ifstream fin("equivalence.in");
ofstream fout("equivalence.out");

int n1, m1, k1, n2, m2, k2;
bool terminales1[vertices];
bool terminales2[vertices];
bitset <vertices> vis[vertices];
graph grafo1, grafo2;

bool bfs() {
    queue <ii> q;
    q.push({1, 1});
    while (!q.empty()) {
        ii u = q.front();
        q.pop();
        if (terminales1[u.ff] != terminales2[u.ss]) return false;
        vis[u.ff][u.ss] = 1;
        REP('a', 'z' + 1) {
            int v1 = grafo1[u.ff][i];
            int v2 = grafo2[u.ss][i];
            if (!vis[v1][v2]) {
                q.push({v1, v2});
            }
        }
    }
    return true;
}

int main () {

    grafo1.assign(vertices, vi(256, 0));
    grafo2.assign(vertices, vi(256, 0));
    fin >> n1 >> m1 >> k1;
    int in1, in2;
    char in3;
    REP(0, k1) {
        fin >> in1;
        terminales1[in1] = true;
    }
    REP(0, m1) {
        fin >> in1 >> in2 >> in3;
        grafo1[in1][in3] = in2;
    }
    fin >> n2 >> m2 >> k2;
    REP(0, k2) {
        fin >> in1;
        terminales2[in1] = true;
    }
    REP(0, m2) {
        fin >> in1 >> in2 >> in3;
        grafo2[in1][in3] = in2;
    }
    bool ans = bfs();
    fout << (ans ? "YES" : "NO") << "\n";
    return 0;
}