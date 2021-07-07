#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	ll n, M;
	cin >> n >> M;

	vector<ll> p(n), c(n);
	for(int i = 0; i < n; ++i)
		cin >> p[i] >> c[i];

	vector<int> id(n);
	iota(id.begin(), id.end(), 0);

	sort(id.begin(), id.end(),
		[&](int x, int y) {return c[x] / p[x] < c[y] / p[y]; });

	const ll oo = 0x3f3f3f3f3f3f3f3f;
	ll d = 0, g = 0, s = 0;

	function<ll()> left = [&]()
	{
		if(s == 0) return oo;
		if(g >= M) return 0ll;

		ll l = 0, r = 5e9;
		while(l + 1 < r)
		{
			ll m = (l + r) >> 1;
			ll f = g + m * s;
			if(f < M) l = m;
			else r = m;
		}
		return r;
	};

	for(auto &i : id)
	{
		ll to = c[i] / p[i] + 1;
		if(d < to)
		{
			ll step = left();

			if(step < to - d) break;

			g += s * (to - d);
			d = to;
		}

		ll add = p[i] - c[i] % p[i];
		g += add;
		s += p[i];
	}

	cout << d + left() << endl;

	return 0;
}