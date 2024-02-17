#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() 
{
	cin.tie(0);
	cout.tie(0);
	int x;
	cin >> x;
	int n;
	while (x--) {
		cin >> n;
		while ((n & 1) == 0) 
		{
			n >>= 1;
			cout << 2 << " ";
		}
		for (ll i = 3; i * i <= n; i += 2)
		{
			while(n % i == 0)
			{
				cout << i << " ";
				n /= i;
			}
		}
		if (n > 1)
		{
			cout << n;
		}
		cout << "\n";
	}
	return 0;
}