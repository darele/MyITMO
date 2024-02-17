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
#define tam 505
#define mod 1000007

using namespace std;

ifstream fin("knight.in");
ofstream fout("knight.out");

ll mat[tam][tam];
int tiempo[tam][tam];
int n, m;

void matriz() {
    REP(0, n) {
        REP2(0, m) {
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }
    RAYA;
}

int main() {

    fin >> n >> m;
    mat[0][0] = 1;
    queue <pair <int, ii> > cola;
    cola.push({0, {0, 0}});
    tiempo[0][0] = 0;
    int cont = 1;
    while (cola.size()) {
        int i, j;
        pair <int, ii> u = cola.front();
        cola.pop();
        i = u.ss.ff;
        j = u.ss.ss;
        if (u.ff != tiempo[i][j]) continue;
        //cout << i << " " << j << endl;
        //matriz();
        if (i + 2 < n && j + 1 < m) {
            mat[i + 2][j + 1] += mat[i][j];
            mat[i + 2][j + 1] %= mod;
            cola.push({cont, {i + 2, j + 1}});
            tiempo[i + 2][j + 1] = cont++;
        }
        if (i + 1 < n && j + 2 < m) {
            mat[i + 1][j + 2] += mat[i][j];
            mat[i + 1][j + 2] %= mod;
            cola.push({cont, {i + 1, j + 2}});
            tiempo[i + 1][j + 2] = cont++;
        }
        if (i + 2 < n && j - 1 >= 0) {
            mat[i + 2][j - 1] += mat[i][j];
            mat[i + 2][j - 1] %= mod;
            cola.push({cont, {i + 2, j - 1}});
            tiempo[i + 2][j - 1] = cont++;
        }
        if (i - 1 >= 0 && j + 2 < m) {
            mat[i - 1][j + 2] += mat[i][j];
            mat[i - 1][j + 2] %= mod;
            cola.push({cont, {i - 1, j + 2}});
            tiempo[i - 1][j + 2] = cont++;
        }
    }
    fout << mat[n - 1][m - 1] << "\n";
    return 0;
}