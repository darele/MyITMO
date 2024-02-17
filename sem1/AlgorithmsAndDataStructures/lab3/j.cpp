#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) 
{
	return b == 0 ? a : gcd(b, a % b);
}

int main() 
{
	int n;
	cin >> n;
	int x, in;
	cin >> x;
	for (int i = 1; i < n; i++) {
		cin >> in;
		x = gcd(in, x);
	}
	cout << x << "\n";
	return 0;
}