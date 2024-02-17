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

ofstream fout("output.txt");

long long generate(int n) {
    long long ans = 0;
    fout << "for n = " << n << "\n";
    for (int i = 0; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            for (int k = j; k <= n; k++) {
                if (n - i - j - k >= i + j) {
                    ans++;
                    fout << i << " " << j << " " << k << " " << n - i - j - k << "\n";
                }
            }
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    REP(0, 30) {
        cout << "n = " << i << ", answer: " << generate(i) << "\n";
    }
    return 0;
}