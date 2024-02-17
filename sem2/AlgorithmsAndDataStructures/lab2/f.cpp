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
#define tam 55

using namespace std;

ifstream fin("knight.in");
ofstream fout("knight.out");

ll mat[tam][tam];

int main() {

    int n, m;
    fin >> n >> m;
    mat[0][0] = 1;
    REP(0, n) {
        REP2(0, m) {
            if (i + 2 < n && j + 1 < m) {
                mat[i + 2][j + 1] += mat[i][j];
            }
            if (i + 1 < n && j + 2 < m) {
                mat[i + 1][j + 2] += mat[i][j];
            }
        }
    }
    fout << mat[n - 1][m - 1] << "\n";
    return 0;
}