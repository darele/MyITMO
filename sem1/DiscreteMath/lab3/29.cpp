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

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    int i;
    string temp;
    int num;
    for (i = 0; s[i] != '=' && i < n; i++) {
        temp += s[i];
    }
    num = stoi(temp);
    vector <int> arr;
    arr.reserve(num);
    while (i < n) {
        temp = "";
        for (i++; i < n && s[i] != '+'; i++) {
            temp += s[i];
        }
        arr.push_back(stoi(temp));
    }
    if (arr.size() == 1) {
        cout << "No solution\n";
        return;
    }
    i = arr.size() - 2;
    arr[i]++;
    int k = arr[i + 1] - 1;
    arr.pop_back();
    //cout << i << endl;
    while (k >= arr[i]) {
        //cout << i << " " << k << " " << arr[i] << endl;
        arr.push_back(arr[i]);
        k -= arr[i];
        i++;
    }
    if (k > 0) {
        arr[i] += k;
    }
    cout << num << "=";
    for (i = 0; i < arr.size() - 1; i++) {
        cout << arr[i] << "+";
    }
    cout << arr.back() << "\n";
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