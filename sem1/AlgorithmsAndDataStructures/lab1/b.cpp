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

void countingsort(vi &arr){
    int n = arr.size();
    vi cont(105, 0);
    REP(0, n) {
        cont[arr[i]]++;
    }
    REP(1, 105) {
        cont[i] += cont[i - 1];
    }
    vi temp(n);
    REP(0, n) {
        temp[cont[arr[i]] - 1] = arr[i];
        cont[arr[i]]--;
    }
    REP(0, n) {
        arr[i] = temp[i];
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vi arr(n);
    REP(0, n) cin >> arr[i];
    countingsort(arr);
    REP(0, n) cout << arr[i] << " ";
    cout << "\n";
    return 0;
}