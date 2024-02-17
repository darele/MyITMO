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

string cifrar(string s) {
    string res = s;
    int l = 0;
    int temp = 1;
    while (temp < s.size()) {
        temp *= 2;
        l++;
    }
    vi a;
    a.reserve(l * 2);
    REP(0, l) {
        a.push_back(0);
        a.push_back(0);
        REP2(0, s.size()) {
            if (s[j] == '1') {
                if (j & (1 << i)) {
                    a[2 * i] ^= 1;
                } else {
                    a[2 * i + 1] ^= 1;
                }
            }
        }
    }
    reverse(a.begin(), a.end());
    REP(0, a.size()) {
        if (a[i] == 1) {
            res += '1';
        } else {
            res += '0';
        }
    }
    return res;
}

string descifrar(string s) {
    int l = 0;
    int temp = 1;
    while (temp + 2 * l < s.size()) {
        temp *= 2;
        l++;
    }
    string s2;
    REP(0, s.size() - 2 * l) s2 += s[i];
    string s3 = cifrar(s2);
    //cout << s3 << "\n" << s << endl;
    int cont = 0;
    REP(0, s3.size()) {
        if (s3[i] != s[i]) cont++;
    }
    if (cont > 1) {
        int num = 0;
        int bit = 0;
        for (int i = s3.size() - 1; i >= s2.size(); i -= 2) {
            if (s3[i] != s[i]) {
                num |= (1 << bit);
            }
            bit++;
        }
        //cout << num << endl;
        if (s2[num] == '0') s2[num] = '1';
        else s2[num] = '0';
    }
    return s2;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    string s;
    cin >> n;
    cin >> s;
    if (n == 1) {
        //cout << 2 << endl;
        cout << cifrar(s) << "\n";
    } else {
        cout << descifrar(s) << "\n";
    }
    return 0;
}