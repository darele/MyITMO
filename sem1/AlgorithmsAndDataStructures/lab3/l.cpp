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

int mcd(int a, int b) {return b == 0 ? a : mcd(b, a % b);}

void solve() {
    int n, d;
    cin >> n >> d;
    int arr[n];
    int tam = 0;
    REP(0, n) {
        cin >> arr[tam];
        if (arr[tam] % d == 0) {
           tam++;
        }
    }
    int m = arr[0];
    int i = 1;
    int ans[n];
    ans[0] = arr[0];
    int tam2 = 1;
    while (i < tam && m != d) {
        m = mcd(arr[i], m);
        ans[tam2++] = arr[i++];
    }
    if (m == d) {
        cout << tam2 << "\n";
        REP(0, tam2) cout << ans[i] << " ";
        cout << "\n";
    } else {
        cout << "-1\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t = 1;
    //cin >> t;
    while (t--) {
        
        solve();
    }
    return 0;
}