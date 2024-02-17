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

string mover(string s) {
    string ans = "";
    int n = s.size();
    REP(0, n) {
        ans += s[(i + 1) % n];
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string s;
    cin >> s;
    int n = s.size();
    vector <string> arr(n);
    arr[0] = s;
    REP(1, n) {
        arr[i] = mover(arr[i - 1]);
    }
    sort(arr.begin(), arr.end());
    REP(0, n) {
        cout << arr[i][n - 1];
    }
    cout << "\n";
    return 0;
}