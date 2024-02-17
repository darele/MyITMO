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
#define tam 105

using namespace std;

ll dp[tam][tam];

void gen() {
    //REP(0, tam) dp[0][i] = 1;
    for (int i = 1; i < tam; i++) {
        dp[i][i] = 1;
    }
    for (int i = 1; i < tam - 1; i++) {
        for (int j = i - 1; j > 0; j--) {
            dp[i][j] = dp[i][j + 1] + dp[i - j][j];
        }
    }
}

void solve() {
    string s;
    cin >> s;
    int n = 0;
    string temp;
    int ant = 0;
    vl arr;
    arr.reserve(105);
    arr.push_back(1);
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '+') {
            temp = "";
            for (int j = ant; j < i; j++) {
                temp += s[j];
            }
            n += stoi(temp);
            arr.push_back(stoi(temp));
            ant = i + 1;
        }
    }
    temp = "";
    for (int j = ant; j < s.size(); j++) {
        temp += s[j];
    }
    n += stoi(temp);
    arr.push_back(stoi(temp));
    gen();
    ll sum = 0;
    ll ans = 0;
    for (int i = 1; i < arr.size(); i++) {
        ans += dp[n - sum][arr[i - 1]];
        ans -= dp[n - sum][arr[i]];
        sum += arr[i];
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t = 1;
    //cin >> t;
    while (t--) {
        
        solve();
    }
    return 0;
};