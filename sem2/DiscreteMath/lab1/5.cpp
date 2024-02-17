#include <bits/stdc++.h>
#define DBG(x) cerr << #x << "=" << (x) << "\n"
#define RAYA cerr << "======================\n"
#define ll long long
#define ii pair <int, int>
#define dl pair <ll, ll>
#define vi vector <int>
#define vl vector <ll>
#define vii vector <ii>
#define graph vector <vii>
#define ff first
#define ss second
#define REP(a, b) for (int i = a; i < b; i++)
#define REP2(a, b) for (int j = a; j < b; j++)
#define REPS(a, b, c) for (int i = a; i < b; i += c)
#define vertices 105
#define stringlen 1005
#define mod 1000000007

using namespace std;

ifstream fin("problem5.in");
ofstream fout("problem5.out");

int n, m, k, l;
bool terminales[vertices];
ll dp[stringlen][30 * vertices];
bitset <256> vis[vertices];
vector <vector <int> > myset;
int distancia[30 * stringlen * vertices];
graph grafo;
int nextcomp;

int main() {

    fin >> n >> m >> k >> l;
    grafo.assign(n + 5, vii());
    myset.assign(30 * stringlen * vertices, vi());
    int in1, in2;
    REP(0, k) {
        fin >> in1;
        terminales[in1] = 1;
    }
    char in3;
    REP(0, m) {
        fin >> in1 >> in2 >> in3;
        grafo[in1].push_back({in3, in2});
    }
    myset[0].push_back(1);
    dp[0][0] = 1;
    distancia[0] = 0;
    vector <int> pila;
    pila.reserve(30 * vertices);
    //Recorremos cada conjunto
    int cantconjuntos = 1;
    for (int i = 0; i < cantconjuntos; i++) {
        //El conjunto cuya distancia l este ya definida, no lo tomamos en cuenta.
        if (distancia[i] == l) {
            continue;
        }
        //Para el conjunto actual, examinamos todas las conexiones desde una letra
        for (int letra = 'a'; letra <= 'z'; letra++) {
            //Luego cada elemento de un conjunto
            bool band = false;
            for (int j = 0; j < myset[i].size(); j++) {
                //Luego revisamos todas las conecciones
                for (int k = 0; k < grafo[myset[i][j]].size(); k++) {
                    //Si la conexion corresponde a la letra que estamos examinando
                    ii v = grafo[myset[i][j]][k];
                    if (v.ff == letra) {
                        //Si no ha sido visitado
                        if (!vis[v.ss][letra]) {
                            band = true;
                            //Lo agregamos a la pila
                            pila.push_back(v.ss);
                            vis[v.ss][letra] = true;
                            myset[cantconjuntos].push_back(v.ss);
                            //calculamos la cantidad de palabras que se pueden formar hacia el
                            dp[distancia[i] + 1][cantconjuntos] += dp[distancia[i]][i];
                            distancia[cantconjuntos] = distancia[i] + 1;
                            //sacar modulo
                            dp[distancia[i] + 1][cantconjuntos] %= mod;
                        }
                    }
                }
            }
            //Al pasar de letra, el numero del siguiente conjunto aumenta
            //solo si encontramos algo con esa letra
            if (band) cantconjuntos++;
            //anular las visitas de todos los vertices que visitamos
            while (!pila.empty()) {
                int v = pila.back();
                pila.pop_back();
                vis[v].reset();
            }
        }
    }

    ll ans = 0;
    //recorrer todos los conjuntos
    for (int i = 0; i < cantconjuntos; i++) {
        //todos sus elementos
        for (int j = 0; j < myset[i].size(); j++) {
            //si es un terminal
            if (terminales[myset[i][j]]) {
                //sumarlo al resultado
                ans += dp[l][i];
                //sacar modulo
                ans %= mod;
            }
        }
    }
    fout << ans << "\n";
    return 0;
}