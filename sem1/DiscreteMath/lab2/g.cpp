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
#define EPS 1e-9

using namespace std;

int n, m;
string s;

string tobinary(int p, int q) {
    string ans = "";
    int i = 0;
    while (i < q) {
        if (p % 2) ans += "1";
        else ans += "0";
        p >>= 1;
        i++;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    cin >> s;
    cout << n << "\n";
    vector <int> rep(n);
    m = s.size();
    REP(0, m) {
        rep[s[i] - 'a']++;
    }
    REP(0, n) {
        cout << rep[i] << " ";
    }
    cout << "\n";
    vector <long long> numrangos(n + 2);
    vector <long long> demrangos(n + 2, m);
    numrangos[0] = 0;
    numrangos[n] = m;
    REP(0, n) {
        numrangos[i + 1] = numrangos[i] + rep[i];
    }
    ll largo, temp;
    REP(0, m) {
        numrangos[0] = numrangos[s[i] - 'a'];
        numrangos[n] = numrangos[s[i] - 'a' + 1];
        largo = numrangos[n] - numrangos[0];
        numrangos[0] *= m;
        numrangos[n] *= m;
        demrangos[0] *= m;
        REP2(1, n + 1) {
            temp = largo * rep[j - 1];
            numrangos[j] = numrangos[j - 1] + temp;
            demrangos[j] *= m;
        }
    }
    return 0;
}

/*rangos[0] = 0;
    rangos[n] = 1;
    double frac = (rangos[n] - rangos[0]) / m;
    REP(1, n + 1) {
        double temp = frac * (double)rep[i - 1];
        rangos[i] = rangos[i - 1] + temp;
    }
    REP(0, m) {
        rangos[0] = rangos[s[i] - 'a'];
        rangos[n] = rangos[s[i] - 'a' + 1];
        frac = (rangos[n] - rangos[0]) / m;
        REP2(1, n + 1) {
            double temp = frac * (double)rep[j - 1];
            rangos[j] = rangos[j - 1] + temp;
        }
    }
    double p = -1;
    for (int q = 1; q < 64 && p == -1; q++) {
        long long ini = 0, fin = (1ll << q) - 1;
        long long mid = (ini + fin) / 2;
        long long t;
        while (ini <= fin) {
            mid = (ini + fin) / 2;
            t = mid;
            long double temp = (long double)t / (1ll << q);
            //cout << rangos[0] << " " << rangos[n] << "\n";
            //cout << temp << "\n";
            if (abs(temp - rangos[0]) < EPS || 
                abs(temp - rangos[n]) < EPS || 
                (temp > rangos[0] && temp < rangos[n])) {
                p = t;
                cout << tobinary(p, q) << "\n";
                break;
            } else {
                if (temp < rangos[0]) ini = mid + 1;
                else fin = mid - 1;
            }
        }
    }*/