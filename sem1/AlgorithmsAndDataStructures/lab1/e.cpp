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

bool solve(int a[], int n) {
    REP(1, n) {
        if (2 * i < n and a[i] > a[2 * i]) return false;
        if (2 * i + 1 < n and a[i] > a[2 * i + 1]) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    int a[n + 1];
    REP(1, n + 1) cin >> a[i];
    cout << (solve(a, n + 1) ? "YES" : "NO") << "\n";
    return 0;
}