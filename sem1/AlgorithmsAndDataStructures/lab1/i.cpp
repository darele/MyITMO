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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    int a[n];
    REP(0, n) cin >> a[i];
    vii ans;
    int i = 0;
    vector <bool> used(n + 1, false);
    stack <int> pila;
    int j = 1;
    while (i<n or j <= n) {
        if (used[j]) {
            if (!pila.empty() and pila.top() == j) {
                pila.pop();
                used[j] = false;
                ans.push_back({2, 1});
                j++;
            }
            else {
                cout << "0\n";
                return 0;
            }
        } else {
            pila.push(a[i]);
            used[a[i]] = true;
            ans.push_back({1, 1});
            i++;
        }
    }
    for (auto x : ans) {
        cout << x.ff << " " << x.ss << "\n";
    }
    return 0;
}