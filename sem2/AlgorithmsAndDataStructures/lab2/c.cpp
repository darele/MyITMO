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

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {

    ll n;
    fin >> n;
    vl cero(n, 0), uno(n, 0);
    cero[0] = 1;
    uno[0] = 1;
    for (int i = 1; i < n; i++) {
        cero[i] = cero[i - 1] + uno[i - 1];
        uno[i] = cero[i - 1];
    }
    fout << cero[n - 1] + uno[n - 1] << "\n";
    return 0;
}