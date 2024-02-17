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

ll C[35][35];

ll combi(int n, int k) {
    if (k == 0) C[n][k] = 1;
    if (n == k) C[n][k] = 1;
    if (C[n][k] != 0) return C[n][k];
    return C[n][k] = combi(n - 1, k - 1) + combi(n - 1, k);
}

void solve() {
    int n, k;
    cin >> n >> k;
    int arr[k + 1];
    arr[0] = 0;
    int ans = 0;
    int i = 1;
    while (k > 0) {
        cin >> arr[i];
        for (int j = arr[i - 1] + 1; j < arr[i]; j++) {
            ans += combi(n - j, k - 1);
            //cout << arr[i] << " " << j << " " << combi(n - j, k - 1) << " " << endl;
        }
        i++;
        k--;
    }
    cout << ans << "\n";
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