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

ifstream fin("fastminimization.in");
ofstream fout("fastminimization.out");

int n, m, k;
graph grafo;
vi grafo_prime[vertices][256];
int terminales[vertices];
bool esterminal[vertices];
vector <vector <int> > P;
int clase[vertices];

void fec() {
    P.reserve(LOG * vertices);
    P.push_back(vi());
    P.push_back(vi());
    REP(1, n + 1) {
        if (esterminal[i]) {
            P[0].push_back(i);
            clase[i] = 0;
        } else {
            P[1].push_back(i);
            clase[i] = 1;
        }
    }
    queue <ii> q;
    for (int i = 'a'; i <= 'z'; i++) {
        q.push({0, i});
    }
    for (int i = 'a'; i <= 'z'; i++) {
        q.push({1, i});
    }
    vector <vector <int> > involved;
    involved.reserve(30 * vertices);
    while (!q.empty()) {
        ii u = q.front();
        q.pop();
        involved.clear();
        for (int q = 'a'; q <= 'z'; q++) {
            for (int r : grafo_prime[q][u.ss]) {
                int i = clase[r];
                while (involved.size() < i + 1) involved.push_back(vi());
                involved[i].push_back(r);
            }
        }
        for (int i = 0; i < involved.size(); i++) {
            if (involved[i].size() < P[i].size()) {
                int j = P.size();
                P.push_back(vi());
                for (int r : involved[i]) {
                    //search
                    for (int k = 0; k < P[i].size(); k++) {
                        //swap
                        if (P[i][k] == r) {
                            swap(P[i][k], P[i].back());
                            //delete
                            P[i].pop_back();
                        }
                    }
                    //add r to P[j]
                    P[j].push_back(r);
                }
                if (P[j].size() > P[i].size()) {
                    swap(P[i], P[j]);
                }
                for (int r : P[j]) {
                    clase[r] = j;
                }
                for (int i = 'a'; i <= 'z'; i++) {
                    q.push({j, i});
                }
            }
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
    fec();
    graph ans;
    ans.assign(n + 5, vi(256, 0));
    int comp[vertices];
    int nuevon = 0;
    for (int i = 0; i < P.size(); i++) {
        if (P[i].size() != 0) nuevon++;
        for (int j : P[i]) {
            comp[j] = nuevon;
        }
    }
    int aristas = 0;
    set <int> nuevosterminales;
    REP(1, n + 1) {
        if (esterminal[i]) {
            nuevosterminales.insert(comp[i]);
        }
        REP2('a', 'z' + 1) {
            if (grafo[i][j] != 0) {
                int u = comp[i];
                int v = comp[grafo[i][j]];
                if (ans[u][j] == 0) {
                    ans[u][j] = v;
                    aristas++;
                }
            }
        }
    }
    fout << nuevon << " " << aristas << " " << nuevosterminales.size() << "\n";
    for (auto i : nuevosterminales) {
        fout << i << " ";
    }
    fout << "\n";
    REP(0, ans.size()) {
        REP2('a', 'z' + 1) {
            if (ans[i][j] != 0) {
                fout << i << " " << ans[i][j] << " " << (char)j << "\n";
            }
        }
    }
    return 0;
}