#include <bits/stdc++.h>

using namespace std;

#ifdef DGC
#include "debug.h"
#else
#define debug(...)
#endif
typedef long long ll;
typedef long double ld;
typedef complex<ld> point;
#define F first
#define S second

template<typename T>
pair<T, vector<int>> min_assignment(const vector<vector<T>> &c)
{
	const int n = c.size(), m = c[0].size(); // assert(n <= m);
	vector<T> v(m), dist(m); // v: potential
	vector<int> matchL(n, -1), matchR(m, -1); // matching pairs
	vector<int> index(m), prev(m);
	iota(index.begin(), index.end(), 0);

	auto residue = [&](int i, int j)
	{
		return c[i][j] - v[j];
	};

	for (int f = 0; f < n; ++f)
	{
		for (int j = 0; j < m; ++j)
		{
			dist[j] = residue(f, j);
			prev[j] = f;
		}
		T w;
		int j, l;
		for (int s = 0, t = 0;;)
		{
			if (s == t)
			{
				l = s;
				w = dist[index[t++]];
				for (int k = t; k < m; ++k)
				{
					j = index[k];
					T h = dist[j];
					if (h <= w)
					{
						if (h < w)
						{
							t = s;
							w = h;
						}
						index[k] = index[t];
						index[t++] = j;
					}
				}
				for (int k = s; k < t; ++k)
				{
					j = index[k];
					if (matchR[j] < 0)
						goto aug;
				}
			}
			int q = index[s++], i = matchR[q];
			for (int k = t; k < m; ++k)
			{
				j = index[k];
				T h = residue(i, j) - residue(i, q) + w;
				if (h < dist[j])
				{
					dist[j] = h;
					prev[j] = i;
					if (h == w)
					{
						if (matchR[j] < 0)
							goto aug;
						index[k] = index[t];
						index[t++] = j;
					}
				}
			}
		}
		aug: for (int k = 0; k < l; ++k)
			v[index[k]] += dist[index[k]] - w;
		int i;
		do
		{
			matchR[j] = i = prev[j];
			swap(j, matchL[i]);
		} while (i != f);
	}
	T opt = 0;
	for (int i = 0; i < n; ++i)
		opt += c[i][matchL[i]]; // (i, matchL[i]) is a solution
	return { opt, matchL };
}


int main()
{
	#ifdef DGC
		//freopen("a.txt", "r", stdin);
		//freopen("b.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(0), cin.tie(0);

	int n;
	cin >> n;
	vector<vector<double>> a(n, vector<double>(n));
	for (auto &i : a)
		for (auto &j : i)
		{
			int x;
			cin >> x;
			j = -log((double)x);
		}

	auto ans = min_assignment<double>(a);
	//cout << ans.F << "\n";
	vector<int> w(n);
	for (auto &i : ans.S)
		w[i] = &i-&ans.S[0];

	for (auto &i : w)
		cout << i+1 << " \n"[&i==&w.back()];

	return 0;
}