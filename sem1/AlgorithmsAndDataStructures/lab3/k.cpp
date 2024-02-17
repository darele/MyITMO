#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a % b);
}

int main() 
{
	int n, d;
	cin >> n >> d;
	vector <int> arr;
	arr.reserve(n);
	int x;
	for (int i = 0; i < n; i++) 
	{
		cin >> x;
		if (x % d == 0)
		{
			arr.push_back(x);
		}
	}
	x = arr[0];
	n = arr.size();
	for (int i = 0; i < n; i++) {
		x = gcd(x, arr[i]);
	}
	if (x == d)
	{
		cout << n << "\n";
		for (int i = 0; i < n; i++)
		{
			cout << arr[i] << " ";
		}
		cout << "\n";
	}
	else
	{
		cout << "-1\n";
	}
}