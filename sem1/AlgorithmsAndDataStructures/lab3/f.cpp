#include <bits/stdc++.h>
#define ll long long
#define lim 20000007

using namespace std;

bitset <lim> vis;

void sieve() 
{
	vis.set();
	for (ll i = 2; i * i < lim; i++) 
	{
		if (vis[i])
		for (ll j = i * i; j < lim; j += i)
		{
			vis[j] = 0;
		}
	}
}

int main() 
{
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	sieve();
	int x;
	while (n--) {
		cin >> x;
		cout << (vis[x] ? "YES" : "NO") << "\n";
	}
	return 0;
}