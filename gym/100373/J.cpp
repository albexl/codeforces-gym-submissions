#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;

const ll oo = 0x3f3f3f3f3f3f3f3f;

struct segment_tree
{
	vector<ll> st, lazy, cnt;

	segment_tree(int n, vector<ll> &v) : st(4 * n), lazy(4 * n), cnt(4 * n)
	{
		build(1, 0, n, v);
	}

	void build(int p, int b, int e, vector<ll> &v)
	{
		if(b + 1 == e)
		{
			st[p] = v[b];
			if(v[b] <= 0)
				st[p] = +oo, cnt[p] = 1;
		}
		else
		{
			int m = (b + e) >> 1, l = p << 1, r = l | 1;
			build(l, b, m, v);
			build(r, m, e, v);
			st[p] = min(st[l], st[r]);
			cnt[p] = cnt[l] + cnt[r];
		}
	}

	void push(int p)
	{
		if(lazy[p])
		{
			int l = p << 1, r = l | 1;

			st[l] += lazy[p];
			lazy[l] += lazy[p];

			st[r] += lazy[p];
			lazy[r] += lazy[p];

			lazy[p] = 0;
		}
	}

	void update(int p, int b, int e, int x, int y, ll v)
	{
		if(x <= b && e <= y)
		{
			st[p] += v;
			lazy[p] += v;
			return;
		}
		else
		{
			push(p);
			int m = (b + e) >> 1, l = p << 1, r = l | 1;

			if(x < m) update(l, b, m, x, y, v);
			if(m < y) update(r, m, e, x, y, v);
			st[p] = min(st[l], st[r]);
		}
	}

	bool good(int p, int b, int e)
	{
		if(b + 1 == e)
		{
			bool ok = st[p] > 0;
			if(!ok)
				st[p] = +oo, cnt[p] = 1;
			return ok;
		}
		else
		{
			push(p);
			int m = (b + e) >> 1, l = p << 1, r = l | 1;
			bool ok;
			if(st[l] == st[p])
				ok = good(l, b, m);
			else
				ok = good(r, m, e);

			st[p] = min(st[l], st[r]);
			cnt[p] = cnt[l] + cnt[r];
			return ok;
		}
	}

	ll count(int p, int b, int e, int x, int y)
	{
		if(x <= b && e <= y)
			return cnt[p];
		else
		{
			push(p);
			ll ans = 0;
			int m = (b + e) >> 1, l = p << 1, r = l | 1;

			if(x < m) ans += count(l, b, m, x, y);
			if(m < y) ans += count(r, m, e, x, y);
			return ans;
		}
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<ll> v(n);
	for(auto &el : v) cin >> el;

	segment_tree st(n, v);

	ll op, a, b, c;
	while(m--)
	{
		cin >> op >> a >> b;

		--a;
		if(op == 0)
		{
			cin >> c;

			st.update(1, 0, n, a, b, -c);
		}
		else
		{
			while(!st.good(1, 0, n));

			cout << st.count(1, 0, n, a, b) << endl;
		}
	}


	return 0;
}