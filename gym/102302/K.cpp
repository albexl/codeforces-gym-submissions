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

struct suffix_array
{
	int n;
	vector<int> sa, lcp, rank;

	suffix_array(const vector<ll> &s, const vector<int> &id) : n(s.size() + 1), sa(n), lcp(n), rank(n)
	{
		vector<int> top(n);
		for (int i = 0; i < n; ++i)
			top[rank[i] = id[i]]++;

		partial_sum(top.begin(), top.end(), top.begin());
		for (int i = 0; i < n; ++i)
			sa[--top[rank[i]]] = i;

		vector<int> tmp(n);
		for (int len = 1, j; len < n; len <<= 1)
		{
			for (int i = 0; i < n; ++i)
			{
				j = sa[i] - len;
				if (j < 0) j += n;
				tmp[top[rank[j]]++] = j;
			}

			sa[tmp[top[0] = 0]] = j = 0;
			for (int i = 1, j = 0; i < n; ++i)
			{
				if (rank[tmp[i]] != rank[tmp[i - 1]]
						|| rank[tmp[i] + len] != rank[tmp[i - 1] + len])
					top[++j] = i;
				sa[tmp[i]] = j;
			}

			copy(sa.begin(), sa.end(), rank.begin());
			copy(tmp.begin(), tmp.end(), sa.begin());
			if (j >= n - 1) break;
		}

		int i, j, k;
		for (j = rank[lcp[i = k = 0] = 0]; i < n - 1; ++i, ++k)
		{
			while (k >= 0 && s[i] != s[sa[j - 1] + k])
				lcp[j] = k--, j = rank[sa[j] + 1];
		}
	}
};

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>     // Including tree_order_statistics_node_update

using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main()
{
	#ifdef DGC
		//freopen("a.txt", "r", stdin);
		//freopen("b.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(0), cin.tie(0);

	int n; ll l, r;
	cin >> n >> l >> r;

	vector<ll> a(n);
	for (auto &i : a) cin >> i;

	auto b = a;
	sort(b.begin(), b.end());
	b.erase(unique(b.begin(), b.end()), b.end());

	vector<int> id(n+1);
	for (int i = 0; i < n; ++i)
		id[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin() + 1;

	suffix_array sa(a, id);

	for (int i = 1; i < n; ++i)
		a[i] += a[i-1];

	debug(sa.sa)
	debug(sa.lcp)

	vector<vector<pair<ll, int>>> op(n);
	for (int i = 1; i <= n; ++i)
	{
		int p = sa.sa[i], lcp = sa.lcp[i];

		if (p + lcp >= n) continue;

		ll x = (!p) ? 0LL : a[p-1];

		op[p + lcp].push_back({ r+x, +1 });
		op[p + lcp].push_back({ l+x-1, -1 });
	}

	ll ans = 0;
	ordered_set<pair<ll, int>> S;

	for (int i = n-1; i >= 0; --i)
	{
		S.insert({ a[i], i });
		for (auto j : op[i])
			ans += (int)S.order_of_key({ j.F, 1<<30 }) * j.S;
	}

	cout << ans << "\n";

	return 0;
}