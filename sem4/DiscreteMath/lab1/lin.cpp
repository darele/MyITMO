#include<iostream>
#include<vector>
using namespace std;
const long long MOD =  104857601ll;
vector<long long> poly_mult(const vector<long long>& A, const vector<long long>& B) {
    int n = A.size() - 1, m = B.size() - 1;
    vector<long long> C(n + m + 1);
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            long long tmp = (j%2 != 0) ? B[j] : -B[j];
            C[i + j] = (C[i + j] + MOD * MOD + A[i] * tmp) % MOD;
        }
    }
    while (C.size() && C.back() == 0) {
        C.pop_back();
    }
    return C;
}
vector<long long> evenOdd(vector<long long> &a, int even) {
    vector<long long> ret(a.size());
    int index = 0;
    for (int i = 0; i < a.size(); i++) {
        if (i % 2 == even) {
            ret[index++] = a[i];
        }
    }
    return ret;
}
int main()
{
    int k,n; cin>>k>>n;
    n--;
    vector<long long> A(2*k,0);
    for(int i = 0; i<k ; i++) cin>>A[i];
    vector<long long> C(k,0);
    for(int i = 0; i<k; i++) cin>>C[i];
    vector<long long> Q(k+1,0);
    Q[0] = 1;
    for(int i = 1; i<=k; i++) Q[i] = (MOD - C[i - 1]) % MOD;
    while(n>=k){
        for(int i = k ; i< 2*k; i++){
            for(int j = 1; j <= k; j++){
                A[i] = (A[i] + MOD * MOD + (-Q[j])*A[i-j])% MOD;
            }
        }
        vector<long long> temp = poly_mult(Q,Q);
        A = evenOdd(A,n%2);
        for (int i = 0; i <= 2*k; i += 2) {
            Q[i >> 1] == temp[i];
        }
        n = n/2;
    }
    cout << A[n] << endl;
    return 0;


}
