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

using namespace std;

ifstream fin("isomorphism.in");
ofstream fout("isomorphism.out");

int n1, n2, m1, m2, k1, k2;
graph grafo1, grafo2;
bitset <vertices> vis;
bitset <vertices> terminal1, terminal2;
int conversion[vertices];

bool dfs(int u1, int u2) {
    vis[u1] = true;
    if (terminal1[u1] != terminal2[u2]) return false;
    bool ans = true;
    conversion[u1] = u2;
    REP('a', 'z' + 1) {
        int v1 = grafo1[u1][i];
        int v2 = grafo2[u2][i];
        if ((v1 == 0) != (v2 == 0)) return false;
        if (vis[v1]) {
            ans = ans && v2 == conversion[v1];
        } else {
            ans = ans && dfs(v1, v2);
        }
    }
    return ans;
}

int main() {

    fin >> n1 >> m1 >> k1;
    int in1, in2;
    char in3;
    grafo1.assign(n1 + 5, vi(256));
    REP(0, k1) {
        fin >> in1;
        terminal1[in1] = 1;
    }
    REP(0, m1) {
        fin >> in1 >> in2 >> in3;
        grafo1[in1][in3] = in2;
    }
    fin >> n2 >> m2 >> k2;
    grafo2.assign(n2 + 5, vi(256));
    REP(0, k2) {
        fin >> in1;
        terminal2[in1] = 1;
    }
    REP(0, m2) {
        fin >> in1 >> in2 >> in3;
        grafo2[in1][in3] = in2;
    }
    bool res = dfs(1, 1);
    fout << (res ? "YES\n" : "NO\n");
    return 0;
}