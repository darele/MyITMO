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

using namespace std;

ifstream fin("useless.in");
ofstream fout("useless.out");

graph grafo;
bitset <256> visitados;
bitset <256> visto;
bitset <256> usado;
bitset <256> eps;

void dfs(char u) {
    visto[u] = true;
    for (string v : grafo[u]) {
        for (char c : v) {
            dfs(c);
        }
    }
}

int main()
{
    grafo.assign(256, vector <string> ());
    int n;
    fin >> n;
    char st;
    fin >> st;
    string s;
    getline(fin, s);   
    REP(0, n) {
        getline(fin, s);
        usado[s[0]] = true;
        if (s.size() < 5) {
            eps[s[0]] = true;
            continue;
        } else {
            grafo[s[0]].push_back(s.substr(5));
        }
    }
    dfs(st);
    REP('A', 'Z' + 1) {
        if(!eps[i])
        {
            for (const string &s : grafo[i]) {
                int cont = 0;
                for (char c : s) {
                    if (eps[c]) {
                        cont++;
                    }
                }
                if (cont == s.size()) {
                    eps[i] = true;
                    i = 'A' - 1;
                    break;
                }
            }
        }
    }
    REP('A', 'Z' + 1) {
        if (eps[i]) {
            grafo[i].clear();
            usado[i] = 0;
            visitados[i] = 1;
        }
    }
    REP('A', 'Z' + 1) {
        if (!visto[i] && usado[i]) {
            visitados[i] = 1;
            usado[i] = 0;
            grafo[i].clear();
        }
    }
    REP('A', 'Z' + 1) {
        for (int k = 0; k < grafo[i].size(); k++) {
            for (int j = 0; j < grafo[i][k].size(); j++) {
                char c = grafo[i][k][j];
                if (!usado[c] && c >= 'A' && c <= 'Z') {
                    //cout << c << endl;
                    visitados[c] = true;
                    grafo[i][k].erase(j, 1);
                }
            }
            //cout << (char)i << " -> ";
            //cout << grafo[i][k] << endl;
        }
    }
    set <pair <char, char> > used;
    REP ('A', 'Z' + 1) {
        used.insert({i, i});
    }
    REP('A', 'Z' + 1) {
        for (string s : grafo[i]) {
            if (s.size() == 1) {
                for (auto x : used) {
                    if (!visitados[s[0]] && x.ss == s[0] && s[0] >= 'A' && s[0] <= 'Z') {
                        used.insert({i, s[0]});
                        i = 'A' - 1;
                        visitados[s[0]] = 1;
                    }
                }
            }
        }
    }
    REP('A', 'Z' + 1) {
        if (visitados[i]) {
            fout << (char)i << " ";
        }
    }
    fout << endl;
    return 0;
}