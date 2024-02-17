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

vi v;

void adjustdown(int pos) {
    if (pos * 2 >= v.size()) return;
    int l = pos * 2;
    int r = pos * 2 + 1;
    if (r >= v.size()) r = l;
    if (v[pos] >= v[l] and v[pos] >= v[r]) return;
    if (v[l] > v[r]) {
        swap(v[l], v[pos]);
        adjustdown(l);
    } else {
        swap(v[r], v[pos]);
        adjustdown(r);
    }
}

void adjustup(int pos) {
    while (pos > 1 && v[pos] > v[pos / 2]) {
        swap(v[pos], v[pos / 2]);
        pos /= 2;
    }
}

void insert(int val) {
    v.push_back(val);
    adjustup(v.size() - 1);
}

int remove() {
    int temp = v[1];
    swap(v[1], v[v.size() - 1]);
    v.pop_back();
    adjustdown(1);
    return temp;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    v.reserve(n);
    v.push_back(0);
    int in1, in2;
    REP(0, n) {
        cin >> in1;
        if (in1 == 0) {
            cin >> in2;
            insert(in2);
        } else {
            cout << remove() << "\n";
        }
    }
    return 0;
}