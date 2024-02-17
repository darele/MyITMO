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
#define lim 10005
#define mod 104857601ll
 
using namespace std;
 
typedef struct pol {
    ll p[lim];
    int grade;
    pol() {
        grade = 0;
        REP(0, lim){
            p[i] = 0;
        }
    }
    pol(int n) {
        grade = n;
        REP(0, lim){
            p[i] = 0;
        }
    }
 
    ll operator[] (int index) {
        return index >= 0 && index <= grade ? p[index] : 0;
    }
 
    void reduce() {
        for (int i = grade; i >= 0; i--) {
            if (p[i] == 0) {
                grade--;
            } else {
                break;
            }
        }
    }
 
    void multiply(pol other) {
        int n = grade + other.grade;
        ll temp[n + 1];
        REP(0, n + 1) {
            temp[i] = 0;
        }
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= i; j++) {
                temp[i] += ((*this)[j] * other[i - j]) % mod;
                temp[i] = (temp[i] + mod * mod) % mod;
            }
        }
        REP(0, n + 1) {
            p[i] = temp[i];
        }
        grade = n;
        reduce();
    }
} pol;
 
void solve() {
    int k;
    ll n;
    cin >> k >> n;
    n--;
    pol a(2 * k - 1);
    pol q(k);
    REP(0, k) {
        cin >> a.p[i];
    }
    q.p[0] = 1;
    REP(1, k + 1) {
        cin >> q.p[i];
        q.p[i] = (mod - q[i]) % mod;
    }
 
    while (n >= k) {
        for (int i = k; i < 2 * k; i++) {
            a.p[i] = 0;
            for (int j = 0; j <= k; j++) {
                a.p[i] += ((-q[j] * a[i - j]) % mod) % mod;
            }
            a.p[i] = (a[i] + mod * mod) % mod;
        }
        pol neq(q.grade);
        REP(0, q.grade + 1) {
            neq.p[i] = q[i];
            if (i % 2) {
                neq.p[i] *= -1;
            }
            neq.p[i] = (neq[i] + mod) % mod;
        }
        //filter
        ll temp[2 * k];
        int j = 0;
        for (int i = 0; i < 2 * k; i++) {
            if (i % 2 == n % 2) {
                temp[j++] = a[i];
            }
        }
        for (int i = 0; i < j; i++) {
            a.p[i] = temp[i];
        }
        //R=Q*neQ
        pol R = q;
        R.multiply(neq);
 
        //Q=R(sqrt(t))
        for (int i = 0; i <= 2 * k; i += 2) {
            q.p[i / 2] = R[i];
        }
         
        n /= 2;
    }
    cout << a[n] << "\n";
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