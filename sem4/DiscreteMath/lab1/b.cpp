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
#define lim 1005
#define mod 998244353

using namespace std;

int power(int a, int n) { 
    int ans = 1; 
    for (; n; n >>= 1, a = 1LL * a * a % mod) 
        if (n & 1) ans = 1LL * ans * a % mod; 
    return ans; 
} 

int inv(int x) { 
    return power(x, mod - 2) % mod;
}

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

    void add(pol other) {
        for (int i = 0; i <= other.grade; i++) {
            p[i] += other[i];
            p[i] %= mod;
        }
        reduce();
    }

    void multiply(pol other) {
        int n = min(grade + other.grade, lim);
        ll temp[n + 1];
        REP(0, n + 1) {
            temp[i] = 0;
        }
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= i; j++) {
                temp[i] += ((*this)[j] * other[i - j]) % mod;
                temp[i] %= mod;
            }
        }
        REP(0, n + 1) {
            p[i] = temp[i];
        }
        grade = n;
        reduce();
    }

    void scalar(ll factor) {
        for (int i = 0; i <= grade; i++) {
            p[i] *= factor;
        }
    }

    void sqrt(int m) {
        pol ans(0);
        ans.p[0] = 1;
        pol temp(0);
        temp.p[0] = 1;
        ll factor = 1;
        for (int i = 1; i < m; i++) {
            factor = (((((factor * inv(2)) % mod) * ((1 - (i - 1) * 2 + mod) % mod)) % mod) * inv(i)) % mod;
            temp.multiply(*this);
            pol preans = temp;
            preans.scalar(factor);
            ans.add(preans);
        }
        ans.reduce();
        ans.print(m - 1);
    }

    void e(int m) {
        pol ans(0);
        ans.p[0] = 1;
        pol temp(0);
        temp.p[0] = 1;
        ll factor = 1;
        for (int i = 1; i < m; i++) {
            factor = ((factor * inv(i)) % mod);
            temp.multiply(*this);
            pol preans = temp;
            preans.scalar(factor);
            ans.add(preans);
        }
        ans.reduce();
        ans.print(m - 1);
    }

    void ln(int m) {
        pol ans(0);
        ans.p[0] = 0;
        pol temp(0);
        temp.p[0] = 1;
        ll factor = 1;
        for (int i = 1; i < m; i++) {
            factor = inv(i % 2 == 1 ? i : (mod - i) % mod);
            temp.multiply(*this);
            pol preans = temp;
            preans.scalar(factor);
            ans.add(preans);
        }
        ans.reduce();
        ans.print(m - 1);
    }

    void print(int m) {
        for (int i = 0; i <= m; i++) {
            cout << p[i] << " ";
        }
        cout << "\n";
    }
} pol;

int n, m;

void solve() {
    cin >> n >> m;
    pol in(n);
    REP(0, n + 1) {
        cin >> in.p[i];
    }
    in.sqrt(m);
    in.e(m);
    in.ln(m);
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