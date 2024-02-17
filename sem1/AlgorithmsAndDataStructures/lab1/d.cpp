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

string ans;
int pivot;

void solve(vi &teclas, vi a, int vengo) {
    REP(0, a.size()) {
        cout << a[i] << " ";
    }
    cout << endl;
    pivot = rand() % a.size();
    cout << "+ " << a[pivot] << endl;
    cin >> ans;
    vi izq, der;
    REP(0, a.size()) {
        if (pivot == i) continue;
        cout << "+ " << a[i] << endl;
        cin >> ans;
        if (ans == "YES") izq.push_back(a[i]);
        else der.push_back(a[i]);
        if (i < a.size() - 1) {
            cout << "+ " << a[pivot] << endl;
            cin >> ans;
        }
    }
    teclas[a[pivot]] = vengo - a.size() + izq.size();
    if (izq.size() > 0) solve(teclas, izq, teclas[a[pivot]]);
    if (der.size() > 0) solve(teclas, der, teclas[a[pivot]] + der.size());
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    srand(time(0));
    int n, q;
    cin >> n >> q;
    vi teclas(n + 1);
    vi prueba(n);
    REP(1, n + 1) prueba[i - 1] = i;
    solve(teclas, prueba, n + 1);
    cout << "! ";
    REP(1, n + 1) cout << teclas[i] << " ";
    cout << endl;
    return 0;
}