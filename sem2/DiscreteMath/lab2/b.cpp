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

int main()
{
    ifstream fin("epsilon.in");
    ofstream fout("epsilon.out");

    graph grafo;

    grafo.assign(256, vector <string> ());
    int n;
    fin >> n;
    char st;
    fin >> st;

    bitset<256> eps;
    eps.reset();
    {
        string s;
        getline(fin, s);
        REP(0, n) {
            getline(fin, s);
            if (s.size() < 5) {
                eps[s[0]] = true;
            } else {
                grafo[s[0]].push_back(s.substr(5));
            }
        }
    }
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
            fout << (char)i << " ";
        }
    }
    return 0;
}