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

const int L = 120;

ll dp[L][100005];
pair<ll, int> pu[L][100005];
pair<ll, ll> aux2[L][100005];

const ll inf = numeric_limits<ll>::min();

struct segment_tree
{
    int n;
    ll a[2 * 100005];

    //segment_tree(int n) : n(n), a(2 * n, inf) {}

    inline void update(int p, ll v)
    {
        for (a[p += n] = v; p /= 2;)
            a[p] = max(a[2 * p], a[2 * p + 1]);
    }

    inline ll query(int l, int r)
    {
        ll g = inf;

        for (l += n, r += n; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1) g = max(g, a[l++]);
            if (r & 1) g = max(g, a[--r]);
        }

        return g;
    }
} st;

ll n, k;

inline void add(int i, int j)
{
	if (dp[i][j] == inf || j == k) return;

	ll a = dp[i][j] - j; // +k
	ll b = n - dp[i][j] + j; // -k / 2

	ll t = (b - 2*a) / 3;
	//cout << i << " " << j << " " << a << " " << b << " " << t << endl;
	//t = max(t, 0LL);
	while (a + t < ((b - t) / 2))
		++t;

	if (t <= k)
		aux2[i][max(t, (ll)j)] = max(aux2[i][max(t, (ll)j)], make_pair(2*a + b, a)); // ???

	t = min(t, k-1);
	while (a + t > ((b - t) / 2))
		--t;

	//t = min(t, (ll)j);
	if (t >= 0 && j <= t)
	{
		pu[i][j] = { 2*a, t };
		//po[i][t].push_back(2*a);
		//aux1[i][t] = max(aux1[i][t], 2 * a); // + 2*k
	}
	//cout << "done "<< i << " " << j << endl;
}

int main()
{
	#ifdef DGC
		freopen("a.txt", "r", stdin);
		//freopen("b.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(0), cin.tie(0);

	cin >> n >> k;

	st.n = k+1;

	for (int i = 0; i < L; ++i)
		for (int j = 0; j <= k; ++j)
		{
			pu[i][j] = { inf, inf };
			aux2[i][j] = { inf, inf };
			dp[i][j] = inf;
		}

	for (ll j = 1; j <= k; ++j)
	{
		dp[1][j] = j + min(j, (n-j)/2);
		add(1, j);

		if (dp[1][j] >= n)
		{
			cout << "1\n";
			return 0;
		}
	}

	//multiset<ll> s;
	for (int i = 2; i < L; ++i)
	{
		//s.clear();
		memset(st.a, 128, sizeof(st.a));
		//cout << st.a[0] << "\n";

		for (int j = 1; j <= k; ++j)
		{
			aux2[i-1][j] = max(aux2[i-1][j], aux2[i-1][j-1]);

			st.update(pu[i-1][j].S, pu[i-1][j].F);
				//s.insert(u);

			ll val = st.query(j, k+1);
			if (val != -9187201950435737472LL)
			{
				dp[i][j] = val + 2*j;
			}
			//debug(i, j, dp[i][j])
			if (aux2[i-1][j].F != inf)
			{
				dp[i][j] = max(dp[i][j], aux2[i-1][j].S + j + (aux2[i-1][j].F - 2*aux2[i-1][j].S - j) / 2);
			}

			if (dp[i][j] >= n)
			{
				cout << i << "\n";
				return 0;
			}

			/*for (auto u : po[i-1][j])
				s.erase(s.find(u));*/

			add(i, j);
		}

		//cout << i << endl;
	}

	/*for (int i = 1; i < 7; ++i)
		for (int j = 1; j <= k; ++j)
			debug(i, j, dp[i][j])*/

	assert(0);

	return 0;
}