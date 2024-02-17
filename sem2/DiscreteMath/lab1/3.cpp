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
#define vertices 100005
#define mod 1000000007

using namespace std;

ifstream fin("problem3.in");
ofstream fout("problem3.out");

int n, m, k;
graph grafo1, grafo2;
ll caminos[vertices];
int terminales[vertices];
bitset <vertices> visitados;
int visciclo[vertices];

ll dfs(int u) {
    if (!visitados[u]) return 0;
    if (caminos[u] != -1) return caminos[u];
    caminos[u] = 0;
    ll ans = 0;
    for (int v : grafo1[u]) {
        ans += dfs(v);
        ans %= mod;
    }
    return caminos[u] = ans;
}

bool detectar_ciclo(int u) {
    if (!visitados[u]) return false;
    if (visciclo[u]) return true;
    visciclo[u] = 1;
    for (int v : grafo1[u]) {
        if (detectar_ciclo(v)) {
            return true;
        }
    }
    visciclo[u] = 0;
    return false;
}

/*
bool detectar_ciclo(int u) {
    if (!visitadosd[u]) {
        visitadosd[u] = 1;
        recstack[u] = 1;
        for (int v : grafo1[u]) {
            if (!visitadosd[v] && detectar_ciclo(v) && visitados[v]) return true;
            else if (recstack[v] && visitados[v]) return true;
        }
    }
    recstack[u] = 0;
    return false;
}
*/

void reversa(int u) {
    if (visitados[u]) return;
    visitados[u] = true;
    for (int v : grafo2[u]) {
        reversa(v);
    }
}

int main() {

    REP(0, vertices) {
        caminos[i] = -1;
    }
    fin >> n >> m >> k;
    grafo1.assign(n + 5, vi());
    grafo2.assign(n + 5, vi());
    REP(0, k) fin >> terminales[i];
    int in1, in2;
    char in3;
    REP(0, m) {
        fin >> in1 >> in2 >> in3;
        grafo1[in1].push_back(in2);
        grafo2[in2].push_back(in1);
    }
    REP(0, k) {
        caminos[terminales[i]] = 1;
        reversa(terminales[i]);
    }
    if (detectar_ciclo(1)) {
        fout << "-1\n";
    } else {
        fout << dfs(1) << "\n";
    }
    return 0;
}