#include<bits/stdc++.h>
#define F first
#define S second
#define PII pair<int,int>
using namespace std;
const int N=105;
vector<int> s;
int n;
void InTruoc(vector<int> s) {
   
    bool tt=1;
    for (int i=n-1;i>=0;i--) {
        if (s[i]>s[i+1]) {
            tt=0;
            for (int j=n;j>i;j--) {
                if (s[i]>s[j]) {
                    swap(s[i],s[j]);
                    reverse(s.begin()+i+1,s.end());
                    break;
                }
            }
            break;
        }
    }
    if (tt) for (int i=0;i<=n;i++) cout<<0<<" ";
    else for (int i=0;i<=n;i++) cout<<s[i]<<" ";
    cout<<"\n";
}
void InSau(vector<int> s) {
   
    bool tt=1;
    for (int i=n-1;i>=0;i--) {
        if (s[i]<s[i+1]) {
            tt=0;
            for (int j=n;j>i;j--) {
                if (s[i]<s[j]) {
                    swap(s[i],s[j]);
                    reverse(s.begin()+i+1,s.end());
                    break;
                }
            }
            break;
        }
    }
    if (tt) for (int i=0;i<=n;i++) cout<<0<<" ";
    else for (int i=0;i<=n;i++) cout<<s[i]<<" ";
    cout<<"\n";
}
int main() {

    ios_base :: sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++) {
        int a;
        cin>>a;
        s.push_back(a);
    }
    n--;
    InTruoc(s);
    InSau(s);
}