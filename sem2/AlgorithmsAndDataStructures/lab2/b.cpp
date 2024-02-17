#include <bits/stdc++.h>
#define DBG(x) cerr << #x << "=" << (x) << "\n"
#define RAYA cerr << "======================\n"
#define ll long long
#define ii pair <int, int>
#define dl pair <ll, ll>
#define vi vector <int>
#define vl vector <ll>
#define vll vector <pair <ll, ii> >
#define vii vector <ii>
#define graph vector <vi>
#define ff first
#define ss second
#define REP(a, b) for (int i = a; i < b; i++)
#define REP2(a, b) for (int j = a; j < b; j++)
#define REPS(a, b, c) for (int i = a; i < b; i += c)
#define inf 100000

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {

    int n, k;
    fin >> n >> k;
    ll arr[n];
    arr[0] = arr[n - 1] = 0;
    REP(1, n - 1) fin >> arr[i];
    vll dp(n, {-inf, {0, 0}});
    dp[0] = {0, {0, 0}};
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= k; j++) {
            if (i - j >= 0) {
                if (arr[i] + dp[i - j].ff > dp[i].ff) {
                    dp[i].ff = arr[i] + dp[i - j].ff;
                    dp[i].ss.ff = dp[i - j].ss.ff + 1;
                    dp[i].ss.ss = i - j;
                }
            }
        }
    }
    fout << dp[n - 1].ff << "\n";
    fout << dp[n - 1].ss.ff << "\n";
    int actual = n - 1;
    vi ans;
    ans.reserve(n);
    while (actual > 0) {
        ans.push_back(actual);
        actual = dp[actual].ss.ss;
    }
    ans.push_back(0);
    for (int i = ans.size() - 1; i >= 0; i--) {
        fout << ans[i] + 1 << " ";
    }
    fout << endl;
    return 0;
}