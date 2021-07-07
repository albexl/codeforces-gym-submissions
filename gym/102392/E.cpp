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

void acc(vector<ll> &x)
{
	for (size_t i = 1; i < x.size(); ++i)
		x[i] += x[i-1];
}

int main()
{
	#ifdef NeverBeRed
		//freopen("a.in", "r", stdin);
		//freopen("a.out", "w", stdout);
	#endif

	ios_base::sync_with_stdio(0), cin.tie(0);

	ll n, k;
	cin >> n >> k;
	ll lc, pc, lm, pm;
	cin >> lc >> pc >> lm >> pm;
	ll t, d; // cost, mov_range
	cin >> t >> d;
	vector<ll> a(n);
	for (auto &i : a) cin >> i;

	a.insert(a.begin(), 0);
	vector<ll> posc(n+1), negc(n+1), pospc(n+1), posm(n+1), negm(n+1);

	sort(a.begin(), a.end());
	for (int i = 1; i <= n; ++i)
	{
		posc[i] = (a[i] >= lc) * min(d, (a[i] - lc));
		negc[i] = (a[i] < lc) * (a[i] - lc);
		if (-negc[i] > d) negc[i] = -1e12;

		posm[i] = (a[i] >= lm) * min(d, (a[i] - lm));
		negm[i] = (a[i] < lm) * (a[i] - lm);
		if (-negm[i] > d) negm[i] = -1e12;

		pospc[i] = min(d, a[i]-1);
	}

	acc(posc), acc(negc), acc(pospc), acc(posm), acc(negm);

	const ll inf = numeric_limits<ll>::max();
	ll ans = inf;
	if (posm[n] >= -negm[n]) ans = n * pm + (-negm[n]) * t;

	for (ll i = n; i > 0; --i)
	{
		ll p = min(i-1, (n-i+1) * (k-1));
		ll need = -(negc[n] - negc[i-1]);
		ll have = posc[n] - posc[i-1];
		have += pospc[p];
		need += -(negm[i-1] - negm[p]);
		have += posm[i-1] - posm[p];
		if (have >= need)
			ans = min(ans, (n-i+1) * pc + (i-1-p) * pm + need * t);
	}
	if (ans == inf) ans = -1;
	cout << ans << "\n";

	return 0;
}