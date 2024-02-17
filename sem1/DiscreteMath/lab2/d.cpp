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

void reorder(string &alfa, int pos) {
    for (int i = pos; i > 0; i--) {
        swap(alfa[i], alfa[i - 1]);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string s;
    cin >> s;
    int n = s.size();
    vector <bool> used(256, false);
    string alfa;
    REP(0, s.size()) {
        if (!used[s[i]]) {
            alfa += s[i];
            used[s[i]] = true;
        }
    }
    sort(alfa.begin(), alfa.end());
    vi ans(n);
    REP(0, n) {
        REP2(0, n) {
            if (s[i] == alfa[j]) {
                ans[i] = j;
                break;
            }
        }
        reorder(alfa, ans[i]);
    }
    REP(0, n) {
        cout << ans[i] + 1 << " ";
    }
    cout << "\n";
    return 0;
}