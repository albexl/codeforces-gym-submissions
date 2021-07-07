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

const ll mod = 1e9+7;
typedef vector<ll> vec;
typedef vector<vec> mat;

mat eye(int n)
{
	mat I(n, vec(n));
	for (int i = 0; i < n; ++i)
		I[i][i] = 1;
	return I;
}

ll add(ll x, ll y, ll M)
{
	return (x + y) % M;
}

ll mul(ll x, ll y, ll M)
{
	return (x * y) % M;
}

mat mul(mat &A, mat &B, ll M)
{
	int l = A.size(), m = B.size(), n = B[0].size();
	mat C(l, vec(n));
	for (int i = 0; i < l; ++i)
		for (int k = 0; k < m; ++k)
			for (int j = 0; j < n; ++j)
				C[i][j] = add(C[i][j], mul(A[i][k], B[k][j], M), M);
	return C;
}

mat pow(mat A, ll b, ll M)
{
	mat X = eye(A.size());
	for (; b > 0; b >>= 1)
	{
		if (b & 1) X = mul(X, A, M);
		A = mul(A, A, M);
	}
	return X;
}

mat m = { {0, 1, 0, 0}, {4, 2, 1, 0}, {0, 0, 2, 0}, {0, 2, 0, 2} };
mat init = {{1}, {6}, {4}, {4}};

ll solve(ll n)
{
	if (n == 1) return 2;
	if (n == 2) return 24;
	if (n == 3) return 96;

	mat p = pow(m, n-2, mod);
	p = mul(p, init, mod);

	ll ans = 4 * p[3][0] % mod;

	p = pow(m, n-3, mod);
	p = mul(p, init, mod);

	ans = (ans + 16 * p[0][0]) % mod;
	return ans;
}

int main()
{
	#ifdef DGC
		//freopen("a.txt", "r", stdin);
		//freopen("b.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(0), cin.tie(0);

	ll n;
	cin >> n;
	cout << solve(n) << "\n";

	return 0;
}