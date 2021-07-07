#include <bits/stdc++.h>

using namespace std;

#ifdef DGC
#include "debug.h"
#else
#define debug(...)
#endif
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
typedef complex<double> point;
#define F first
#define S second

vector<int> solve(vector<int> a, int k)
{
	int n = a.size();
	vector<int> r(n);

	int last = 0;
	for (auto &i : a)
	{
		i += last;
		last = i;
	}

	for (int i = k-1; i < n; ++i)
		r[i] = a[i] - ((i-k < 0) ? 0 : a[i-k]);

	return r;
}

int main()
{
	#ifdef DGC
		//freopen("a.in", "r", stdin);
		//freopen("b.out", "w", stdout);
	#endif

	ios_base::sync_with_stdio(0), cin.tie(0);

	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (auto &i : a) cin >> i;

	if (2*k >= n)
	{
		cout << accumulate(a.begin(), a.end(), 0LL) << "\n";
		return 0;
	}

	auto r = solve(a, k);
	reverse(a.begin(), a.end());
	auto r2 = solve(a, k);
	reverse(r2.begin(), r2.end());

	debug(r)
	debug(r2)

	int ans = 0;
	r2.push_back(0);

	for (int i = n-1; i >= 0; --i)
		r2[i] = max(r2[i], r2[i+1]);

	for (int i = k-1; i < n; ++i)
		ans = max(ans, r[i] + r2[i+1]);

	cout << ans << "\n";

	return 0;
}