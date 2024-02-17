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

int buscar(vector <string> &dic, vi &values, string s) {
    int n = s.size();
    REP(0, dic.size()) {
        if (dic[i] == s) return values[i];
    }
    return -1;
}

string busqueda(vector <string> &dic, vi &values, int x) {
    int n = dic.size();
    REP(0, n) {
        if (values[i] == x) return dic[i];
    }
    return "";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector <int> arr(n);
    REP(0, n) {
        cin >> arr[i];
    }
    vector <string> dic;
    vi values;
    values.reserve(n * n);
    dic.reserve(n * n);
    REP(0, n) {
        if (arr[i] < 26) {
            dic.push_back(string(1, arr[i] + 'a'));
            values.push_back(arr[i]);
        }
    }
    string temp = "";
    string ans = "";
    string ans2 = "";
    string P = "";
    int j = 26, k = 0;
    REP(0, n) {
        temp = busqueda(dic, values, arr[i]);
        if (temp != "") {
            ans += temp;
        } else {
            ans2 = ans;
            while (k < ans2.size()) {
                if (buscar(dic, values, P + ans2[k]) != -1) {
                    P += ans2[k];
                } else {
                    dic.push_back(P + ans2[k]);
                    values.push_back(j++);
                    P = string(1, ans2[k]);
                }
                k++;
            }
            temp = busqueda(dic, values, arr[i]);
            if (temp == "") {
                ans2 += P;
                while (k < ans2.size()) {
                    if (buscar(dic, values, P + ans2[k]) != -1) {
                        P += ans2[k];
                    } else {
                        dic.push_back(P + ans2[k]);
                        values.push_back(j++);
                        P = string(1, ans2[k]);
                    }
                    k++;
                }
                temp = busqueda(dic, values, arr[i]);
            }
            ans += temp;
        }
    }
    cout << ans;
    cout << "\n";
    return 0;
}