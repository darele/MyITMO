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

long long ans;

void merge(int a[], int l1, int r1, int l2, int r2) {
    int n1 = r1 - l1 + 1;
    int n2 = r2 - l2 + 1;
    int a1[n1];
    int a2[n2];
    for (int i = 0; i < n1; i++) a1[i] = a[l1 + i];
    for (int i = 0; i < n2; i++) a2[i] = a[l2 + i];
    int i = 0, j = 0, k = l1;
    while (i < n1 and j < n2) {
        if (a1[i] < a2[j]) {
            a[k] = a1[i++];
        } else {
            a[k] = a2[j++];
            ans = ans + n1 - i;
        }
        k++;
    }
    while (i < n1) {
        a[k] = a1[i++];
        k++;
    }
    while (j < n2) {
        a[k] = a2[j++];
        k++;
    }
}

void mergesort(int a[], int ini, int fin) {
    if (fin > ini) {
        int mid = (ini + fin) / 2;
        mergesort(a, ini, mid);
        mergesort(a, mid + 1, fin);
        merge(a, ini, mid, mid + 1, fin);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    int a[n];
    REP(0, n) cin >> a[i];
    mergesort(a, 0, n-1);
    cout << ans << "\n";
    return 0;
}