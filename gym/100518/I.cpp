#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<ll, ll> pii;

struct fenwick_tree
{
	int n;
	vector<ll> ft;

	fenwick_tree(int _n) : n(_n + 5), ft(n) { }

	void update(int p, ll v)
	{
		for(; p < n; p += p & -p)
			ft[p] += v;
	}

	ll query(int p)
	{
		ll ans = 0;
		for(; p > 0; p -= p & -p)
			ans += ft[p];
		return ans;
	}
};

struct disjoint_set
{
	vector<int> p;

	disjoint_set(int n) : p(n, -1) { }

	int root(int x) { return p[x] < 0 ? x : p[x] = root(p[x]); }

	void merge(int x, int y)
	{
		if((x = root(x)) == (y = root(y))) return;
		if(x > y) swap(x, y);
		p[x] += p[y];
		p[y] = x;
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	freopen("intelligent.in", "r", stdin);
	freopen("intelligent.out", "w", stdout);

	int n;
	while(cin >> n && n)
	{
		vector<pii> exam(n);
		for(auto &e : exam)
			cin >> e.first >> e.second, ++e.second;

		int m; cin >> m;
		vector<pii> seg(m);
		for(auto &s : seg)
			cin >> s.first >> s.second;

		vector<int> v(n);
		iota(v.begin(), v.end(), 0);

		sort(v.begin(), v.end(), [&](int x, int y)
		    { return exam[x].first < exam[y].first; });
		sort(seg.begin(), seg.end());

		ll t = 0, to = 0, it = 0;
		vector<ll> T;
		while(T.size() < v.size() && it < (int)seg.size())
		{
			if(exam[v[T.size()]].first < seg[it].first)
			{
				T.emplace_back(exam[v[T.size()]].first - t - to);
				t = exam[v[T.size() - 1]].first;
				to = 0;
			}
			else
				to += seg[it].second - seg[it].first + 1, ++it;
		}

		while(T.size() < v.size())
		{
			T.emplace_back(exam[v[T.size()]].first - t - to);
			t = exam[v[T.size() - 1]].first;
			to = 0;
		}

		fenwick_tree ft(n);
		disjoint_set ds(n);

		for(int i = 0; i < n; ++i)
		{
			ft.update(i + 1, T[i]);
			exam[v[i]].first = i;
		}

		sort(v.begin(), v.end(), [&](int x, int y)
		{
			if(exam[x].second == exam[y].second)
				return exam[x].first > exam[y].first;
			return exam[x].second < exam[y].second;
		});

		vector<int> opt;
		for(auto e : v)
		{
			auto x = exam[e];
			ll q = ft.query(x.first + 1), p = x.first;
			if(q < x.second) continue;

			q = x.second;
			while(q > 0)
			{
				if(T[p] > 0)
				{
					ll mn = min(T[p], q);
					T[p] -= mn;
					q -= mn;
					ft.update(p + 1, -mn);
				}
				else
				{
					p = ds.root(p);
					if(T[p] == 0 && p > 0)
						ds.merge(p - 1, p);
					p = ds.root(p);
				}
			}
			opt.emplace_back(e + 1);
		}

		sort(opt.begin(), opt.end());
		cout << opt.size() << endl;
		for(int i = 0; i < (int)opt.size(); ++i)
			cout << opt[i] << " \n"[i + 1 == (int)opt.size()];
	}

	return 0;
}