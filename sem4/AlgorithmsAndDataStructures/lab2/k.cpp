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

vi sort_cyclic_shifts(string const &s) {
    int n = s.size();
    int alphabet = 256;
    vi p(n), c(n), cnt(max(alphabet, n), 0);
    for (int i = 0; i < n; i++) {
        cnt[s[i]]++;
    }
    for (int i = 1; i < alphabet; i++) {
        cnt[i] += cnt[i - 1];
    }
    for (int i = 0; i < n; i++) {
        p[--cnt[s[i]]] = i;
    }
    c[p[0]] = 0;
    int classes = 1;
    for (int i = 1; i < n; i++) {
        if (s[p[i]] != s[p[i - 1]]) {
            classes++;
        }
        c[p[i]] = classes - 1;
    }
    vi pn(n), cn(n);
    for (int h = 0; (1 << h) < n; ++h) {
        for (int i = 0; i < n; i++) {
            pn[i] = p[i] - (1 << h);
            if (pn[i] < 0) {
                pn[i] += n;
            }
        }
        cnt.assign(cnt.size(), 0);
        for (int i = 0; i < n; i++) {
            cnt[c[pn[i]]]++;
        }
        for (int i = 1; i < classes; i++) {
            cnt[i] += cnt[i - 1];
        }
        for (int i = n - 1; i >= 0; i--) {
            p[--cnt[c[pn[i]]]] = pn[i];
        }
        cn[p[0]] = 0;
        classes = 1;
        for (int i = 1; i < n; i++) {
            ii cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
            ii prev = {c[p[i - 1]], c[(p[i - 1] + (1 << h)) % n]};
            if (cur != prev) {
                ++classes;
            }
            cn[p[i]] = classes - 1;
        }
        c.swap(cn);
    }
    return p;
}

vi suffarr(string &s) {
    s += "$";
    vi suffarr = sort_cyclic_shifts(s);
    return suffarr;
}

vi lcp(string &s, vi &arr) {
    vi pos(arr.size(), 0);
    for (int i = 1; i < arr.size(); i++) {
        pos[arr[i]] = i;
    }
    vi lcp(arr.size(), 0);
    int computed = 1;
    int k = 0;
    for (int i = 0; i < arr.size(); i++) {
        int j = arr[pos[i] - 1];
        while (i + k < s.size() && j + k < s.size() && s[(i + k) % s.size()] == s[(j + k) % s.size()]) {
            k++;
        }
        lcp[pos[i]] = k;
        if (k > 0) {
            k--;
        }
    }
    return lcp;
}

void solve() {
    string s;
    cin >> s;
    vi arr = suffarr(s);
    vi l = lcp(s, arr);
    vl truelcp(l.size());
    for (int i = 0; i < l.size(); i++) {
        truelcp[i] = l[i];
    }
    ll n = (s.size() - 1);
    ll ans = (n + n * n) / 2;
    for (int i = 1; i <= n; i++) {
        ans -= truelcp[i];
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
}