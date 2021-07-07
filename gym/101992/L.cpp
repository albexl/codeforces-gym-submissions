#include <bits/stdc++.h>

using namespace std;

#ifdef DGC
#include "debug.h"
#else
#define debug(...) 9715;
#endif
typedef long long ll;
typedef long double ld;
typedef complex<double> point;
#define F first
#define S second

struct segment_tree
{
	struct node
	{
		int x; bool neg; int add;

		inline void build(int pos)
		{
			x = pos;
			neg = false;
			add = 0;
		}

		inline bool has_lazy()
		{
			return neg || add != 0;
		}

		inline void clean_lazy()
		{
			neg = false;
			add = 0;
		}
	};

	struct update_info
	{
		int add;
	};

private:

	// propagate lazy of p into u
	inline void prop(node &p, node &u)
	{
		u.x = (p.neg ? -1 : +1) * u.x + p.add;
		u.neg ^= p.neg;
		if (p.neg) u.add *= -1;
		u.add += p.add;
	}

	// update u with x
	inline void apply(node &u, update_info &x)
	{
		u.x = -u.x + x.add;
		u.add *= -1;
		u.neg ^= 1;
		u.add += x.add;
	}

	inline void push(node &u, int b, int e, int m)
	{
		if (u.has_lazy())
		{
			prop(u, st[id(b, m)]);
			prop(u, st[id(m, e)]);
			u.clean_lazy();
		}
	}

	inline int id(int b, int e) { return (b+e-1) | (b!=e-1); }

	void build(int b, int e)
	{
		node &cur = st[id(b, e)];

		if (b+1 == e)
		{
			cur.build(b);
			return;
		}

		int m = (b+e+1)>>1;
		build(b, m);
		build(m, e);
	}

	void update(int b, int e, int lo, int hi, update_info &x)
	{
		node &cur = st[id(b, e)];

		if (lo <= b && e <= hi)
		{
			apply(cur, x);
			return;
		}

		int m  = (b+e+1)>>1;
		push(cur, b, e, m);

		if (lo < m) update(b, m, lo, hi, x);
		if (m < hi) update(m, e, lo, hi, x);
	}

	node query(int b, int e, int lo, int hi)
	{
		node &cur = st[id(b, e)];

		if (lo <= b && e <= hi)
			return cur;

		int m = (b+e+1)>>1;
		push(cur, b, e, m);

		node l, r, u;
		if (lo < m) l = query(b, m, lo, hi);
		if (m < hi) r = query(m, e, lo, hi);
		if (!(lo < m)) return move(r);
		if (!(m < hi)) return move(l);
		assert(0);
	}

	int n;
	vector<node> st;

public:
	void build()
	{
		build(0, n);
	}

	void update(int lo, int hi, update_info x)
	{
		update(0, n, lo, hi+1, x);
	}

	node query(int lo, int hi)
	{
		return query(0, n, lo, hi+1);
	}

	segment_tree(int n) : n(n), st(2*n) {}
};

int main()
{
	#ifdef DGC
		//freopen("b.out", "w", stdout);
	#endif

	freopen("reflection.in", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		int q;
		cin >> q;

		const int N = 100000;
		segment_tree st(N+1);
		st.build();
		for (int x; q--; )
		{
			cin >> x;
			int v = st.query(x, x).x;
			cout << v << "\n";
			st.update(x, N, { 2*v });
		}
	}

	return 0;
}