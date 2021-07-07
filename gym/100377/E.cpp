#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> mat;

const int maxn = 1e5 + 5, mxlog = 17, mod = 1e9 + 7;

int lf[maxn][mxlog][2][2], rg[maxn][mxlog][2][2];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, q;
	cin >> n >> q;

	for(int i = 0, a, b, c, d; i < n; ++i)
	{
		cin >> a >> b >> c >> d;
		rg[i][0][0][0] = lf[i][0][0][0] = a;
		rg[i][0][0][1] = lf[i][0][1][0] = b;
		rg[i][0][1][0] = lf[i][0][0][1] = c;
		rg[i][0][1][1] = lf[i][0][1][1] = d;
	}

	for(int k = 1; k < mxlog; ++k)
		for(int i = 0, nx = 1 << (k - 1); i + nx + nx <= n; ++i)
		{
			lf[i][k][0][0] = ((ll)lf[i][k - 1][0][0] * lf[i + nx][k - 1][0][0] % mod
					         +(ll)lf[i][k - 1][0][1] * lf[i + nx][k - 1][1][0] % mod) % mod;
			lf[i][k][0][1] = ((ll)lf[i][k - 1][0][0] * lf[i + nx][k - 1][0][1] % mod
							 +(ll)lf[i][k - 1][0][1] * lf[i + nx][k - 1][1][1] % mod) % mod;
			lf[i][k][1][0] = ((ll)lf[i][k - 1][1][0] * lf[i + nx][k - 1][0][0] % mod
							 +(ll)lf[i][k - 1][1][1] * lf[i + nx][k - 1][1][0] % mod) % mod;
			lf[i][k][1][1] = ((ll)lf[i][k - 1][1][0] * lf[i + nx][k - 1][0][1] % mod
							 +(ll)lf[i][k - 1][1][1] * lf[i + nx][k - 1][1][1] % mod) % mod;

			rg[i][k][0][0] = ((ll)rg[i][k - 1][0][0] * rg[i + nx][k - 1][0][0] % mod
					         +(ll)rg[i][k - 1][0][1] * rg[i + nx][k - 1][1][0] % mod) % mod;
			rg[i][k][0][1] = ((ll)rg[i][k - 1][0][0] * rg[i + nx][k - 1][0][1] % mod
							 +(ll)rg[i][k - 1][0][1] * rg[i + nx][k - 1][1][1] % mod) % mod;
			rg[i][k][1][0] = ((ll)rg[i][k - 1][1][0] * rg[i + nx][k - 1][0][0] % mod
							 +(ll)rg[i][k - 1][1][1] * rg[i + nx][k - 1][1][0] % mod) % mod;
			rg[i][k][1][1] = ((ll)rg[i][k - 1][1][0] * rg[i + nx][k - 1][0][1] % mod
							 +(ll)rg[i][k - 1][1][1] * rg[i + nx][k - 1][1][1] % mod) % mod;
		}

	while(q--)
	{
		ll k, v, a, b;
		cin >> k >> v >> a >> b;

		if(a <= b)
		{
			--a;
			int a00 = 1, a01 = 0, a10 = 0, a11 = 1;

			for(int k = mxlog - 1, p2 = 1 << k; k >= 0; --k, p2 >>= 1)
				if(a + p2 <= b)
				{
					int na, nb, nc, nd;
					na = ((ll) a00 * lf[a][k][0][0] % mod + (ll) a01 * lf[a][k][1][0] % mod) % mod;
					nb = ((ll) a00 * lf[a][k][0][1] % mod + (ll) a01 * lf[a][k][1][1] % mod) % mod;
					nc = ((ll) a10 * lf[a][k][0][0] % mod + (ll) a11 * lf[a][k][1][0] % mod) % mod;
					nd = ((ll) a10 * lf[a][k][0][1] % mod + (ll) a11 * lf[a][k][1][1] % mod) % mod;

					a00 = na, a01 = nb, a10 = nc, a11 = nd;
					a += p2;nb = ((ll) a00 * lf[a][k][0][0] % mod + (ll) a01 * lf[a][k][1][0]) % mod;
				}

			cout << ((ll)k * a00 % mod + (ll)v * a10 % mod) % mod << " ";
			cout << ((ll)k * a01 % mod + (ll)v * a11 % mod) % mod << endl;
		}
		else
		{
			swap(a, b);
			--a;
			int a00 = 1, a01 = 0, a10 = 0, a11 = 1;

			for(int k = mxlog - 1, p2 = 1 << k; k >= 0; --k, p2 >>= 1)
				if(a + p2 <= b)
				{
					int na, nb, nc, nd;
					na = ((ll) a00 * rg[a][k][0][0] % mod + (ll) a01 * rg[a][k][1][0] % mod) % mod;
					nb = ((ll) a00 * rg[a][k][0][1] % mod + (ll) a01 * rg[a][k][1][1] % mod) % mod;
					nc = ((ll) a10 * rg[a][k][0][0] % mod + (ll) a11 * rg[a][k][1][0] % mod) % mod;
					nd = ((ll) a10 * rg[a][k][0][1] % mod + (ll) a11 * rg[a][k][1][1] % mod) % mod;

					a00 = na, a01 = nb, a10 = nc, a11 = nd;
					a += p2;nb = ((ll) a00 * rg[a][k][0][0] % mod + (ll) a01 * rg[a][k][1][0]) % mod;
				}

			cout << ((ll)k * a00 % mod + (ll)v * a01 % mod) % mod << " ";
			cout << ((ll)k * a10 % mod + (ll)v * a11 % mod) % mod << endl;
		}
	}

	return 0;
}