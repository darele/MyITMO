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

using namespace std;

ifstream fin("automaton.in");
ofstream fout("automaton.out");

graph grafo;
char raiz;

bool check(char u, string &s, int ini) {
    for (string v : grafo[u]) {
        if (v[0] == s[ini]) {
            if (v.size() == 1) {
                if (s.size() - ini == 1) {
                    return true;
                }
            } else {
                if (s.size() - ini >= 1 && check(v[1], s, ini + 1)) {
                    return true;
                }
            }
        } else if (v[0] >= 'A' && v[0] <= 'Z') {
            if (check(v[0], s, ini)) return true;
        }
    }
    return false;
}

int main() {

    int n;
    fin >> n >> raiz;
    grafo.assign(256, vector <string> ());
    string s2;
    char s1;
    REP(0, n) {
        fin >> s1 >> s2 >> s2;
        grafo[s1].push_back(s2);
    }
    int m;
    fin >> m;
    REP(0, m) {
        fin >> s2;
        bool ans = check(raiz, s2, 0);
        fout << (ans ? "yes" : "no") << "\n";
    }
    return 0;
}