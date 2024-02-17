#include <bits/stdc++.h>
#define DBG(x) cerr << #x << "=" << (x) << "\n"
#define RAYA cerr << "======================\n"
#define ll long long
#define ii pair <ll, int>
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

vi p;
vl val;
int tam;
queue <ii> cola;

void merge(int u, int v) {
    p[u] = tam;
    p[v] = tam;
    p[tam] = tam;
    val[tam] = val[u] + val[v];
    cola.push({val[tam], tam});
    tam++;
}

int altura(int u) {
    if (p[u] == u) return 0;
    return 1 + altura(p[u]);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    tam = n;
    val.resize(4 * n);
    p.resize(4 * n);
    //h.resize(n);
    REP(0, 4 * n) p[i] = i;
    vi a(n);
    REP(0, n) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int j = 0;
    REP(0, n) {
        val[i] = a[i];
    }
    j = 0;
    while (j < n) {
        int x, y;
        if (cola.empty() || (j < n and val[j] < cola.front().ff)) {
            x = j;
            j++;
        } else {
            x = cola.front().ss;
            cola.pop();
        }
        if (cola.empty() || (j < n and val[j] < cola.front().ff)) {
            y = j;
            j++;
        } else {
            y = cola.front().ss;
            cola.pop();
        }
        merge(x, y);
    }
    while (cola.size() > 1) {
        int x, y;
        x = cola.front().ss;
        cola.pop();
        y = cola.front().ss;
        cola.pop();
        merge(x, y);
    }
    ll suma = 0;
    REP(0, n) {
        ll temp = altura(i);
        suma += temp * val[i];
    }
    cout << suma << "\n";
    return 0;
}