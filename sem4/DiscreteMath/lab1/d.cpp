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
#define lim 15

using namespace std;

dl reduce(dl f) {
    for (int i = 2; i <= min(f.ff, f.ss); i++) {
        while (f.ff % i == 0 && f.ss % i == 0) {
            f.ff /= i;
            f.ss /= i;
        }
    }
    return f;
}

dl sumfrac(dl f1, dl f2) {
    ll comdem = f1.ss * f2.ss;
    dl ans = {0, comdem};
    ans.ff += (comdem / f1.ss) * f1.ff;
    ans.ff += (comdem / f2.ss) * f2.ff;
    return reduce(ans);
}

typedef struct pol {
    vector <dl> p;
    pol() {
        p.resize(1);
        p[0] = {1, 1};
    }
    pol(int n) {
        p.resize(n + 1);
        REP(0, n + 1) {
            p[i] = {0, 1};
        }
    }
    pol multiply(pol other) {
        int n = other.p.size() + p.size();
        pol ans(n - 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                if (i - j >= other.p.size()) {
                    continue;
                }
                dl f1 = p[j];
                dl f2 = other.p[i - j];
                ans.p[i] = sumfrac(ans.p[i], {f1.ff * f2.ff, f1.ss * f2.ss});
            }
        }
        ans.norm();
        return ans;
    }

    pol add(pol other) {
        int n = max(other.p.size(), p.size());
        pol ans(n);
        int i;
        for (i = 0; i < min(p.size(), other.p.size()); i++) {
            dl f1, f2;
            f1 = p[i];
            f2 = other.p[i];
            ans.p[i] = sumfrac(f1, f2);
        }
        for (; i < p.size(); i++) {
            ans.p[i] = p[i];
        }
        for (; i < other.p.size(); i++) {
            ans.p[i] = other.p[i];
        }
        ans.norm();
        return ans;
    }
    void scalar(dl c) {
        for (int i = 0; i < p.size(); i++) {
            p[i].ff *= c.ff;
            p[i].ss *= c.ss;
            p[i] = reduce(p[i]);
        }
    }
    void norm() {
        while (!p.empty() && p.back().ff == 0) {
            p.pop_back();
        }
    }
} pol;

pol f(int n, int k) {
    dl fac = {1, 1};
    for (int i = 1; i <= k; i++) {
        fac.ss *= i;
    }
    pol ans;
    for (int i = 1; i <= k; i++) {
        pol other(1);
        other.p[0] = {i + n, 1};
        other.p[1] = {1, 1};
        ans = ans.multiply(other);
        cout << ans.p.size() << endl;
        for (int i = 0; i < ans.p.size(); i++) {
            cout << ans.p[i].ff << "/" << ans.p[i].ss << " ";
        }
        cout << endl;
    }
    ans.scalar(fac);
    return ans;
}

int r, k;

void solve() {
    cin >> r >> k;
    pol poli(k);
    ll dem = 1;
    vector <pol> proc;
    proc.reserve(k + 1);
    REP(0, k + 1) {
        cin >> poli.p[i].ff;
        poli.p[i].ss = dem;
        poli.p[i] = reduce(poli.p[i]);
        if (i > 0) {
            dem *= r;
        }
        pol temp = f(-i, k);
        temp.scalar(poli.p[i]);
        proc.push_back(temp);
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