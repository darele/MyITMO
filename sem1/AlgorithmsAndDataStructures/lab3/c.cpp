#include <bits/stdc++.h>
#define ll long long
#define vi vector <ll>

using namespace std;

class DS 
{
public:
	vi p, r, s;
	DS(int n) 
	{
		p.resize(n + 5);
		r.assign(n + 5, 0);
		s.assign(n + 5, 0);
		for (int i = 0; i < n + 5; i++) 
		{
			p[i] = i;
		}
	}
	void sumexp(int u) 
	{
		if (p[u] == p[p[u]])
		{
			return;
		}
		sumexp(p[u]);
		s[u] += s[p[u]];
	}
	int findset(int u)
	{
		return u == p[u] ? u : p[u] = findset(p[u]);
	}
	bool sameset(int u, int v)
	{
		return findset(u) == findset(v);
	}
	void merge(int u, int v)
	{
		sumexp(u);
		int x = findset(u);
		sumexp(v);
		int y = findset(v);
		if (x == y)
		{
			return;
		}
		if (r[x] >= r[y])
		{
			p[y] = x;
			if (r[x] == r[y])
			{
				r[x]++;
			}
			s[y] -= s[x];
		}
		else
		{
			p[x] = y;
			s[x] -= s[y];
		}
		//cout << x << " " << p[x] << "  " << y << " " << p[y] << endl;
	}
};

int main() 
{
	int n, m;
	cin >> n >> m;
	ll in2, in3;
	string in1;
	DS kika(n);
	for (int i = 0; i < m; i++)
	{
		cin >> in1 >> in2;
		if (in1 == "add")
		{
			cin >> in3;
			int temp = kika.findset(in2);
			kika.s[temp] += in3;
		}
		else if (in1 == "join")
		{
			cin >> in3;
			kika.merge(in2, in3);
		}
		else
		{
			kika.sumexp(in2);
			if (kika.findset(in2) == in2) 
			{
				cout << kika.s[in2] << "\n";
			}
			else
			{
				cout << kika.s[in2] + kika.s[kika.findset(in2)] << "\n";
			}
		}
	}
	return 0;
}