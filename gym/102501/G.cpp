#include <bits/stdc++.h>

using namespace std;

#ifdef DGC
#include "debug.h"
#else
#define debug(...) 9715
#endif
typedef long long ll;
typedef long double ld;
typedef complex<int> point;
#define F first
#define S second


int main()
{
	#ifdef NeverBeRed
		freopen("a.in", "r", stdin);
		//freopen("a.out", "w", stdout);
	#endif

	ios_base::sync_with_stdio(0), cin.tie(0);

	int s, l, n;
	cin >> s >> l >> n;
	vector<string> a(s);
	for (auto &i : a) cin >> i;
	sort(a.begin(), a.end());

	auto get = [&](const string &s)
	{
		return lower_bound(a.begin(), a.end(), s) - a.begin();
	};

	vector<vector<bool>> f(s, vector<bool>(s));
	for (string a, b; l--; )
	{
		cin >> a >> b;
		int ia = get(a);
		int ib = get(b);
		f[ia][ib] = f[ib][ia] = true;
	}

	for (int i = 0; i < s; ++i)
		f[i][i] = true;

	vector<int> v(n);
	string x;
	for (int i = 0; i < n; ++i)
	{
		cin >> x;
		v[i] = get(x);
	}

	typedef pair<int, int> pii;
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	vector<int> deg(n), to(n, n), mark(s, -1);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < s; ++j)
			if (mark[j] != -1 && !f[v[i]][j])
				++deg[i];
		if (mark[v[i]] != -1) to[mark[v[i]]] = i;
		mark[v[i]] = i;
		if (!deg[i])
			pq.push({ v[i], i });
	}

	int it = n;
	for (int ta, id; !pq.empty(); )
	{
		tie(ta, id) = pq.top();
		pq.pop();

		cout << a[ta] << " \n"[!--it];

		for (int i = id+1; i < to[id]; ++i)
			if (!f[v[i]][ta] && !--deg[i])
				pq.push({ v[i], i });
	}

	return 0;
}