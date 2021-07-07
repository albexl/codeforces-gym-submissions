#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define double long double

typedef long long ll;
typedef pair<int, int> pii;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	freopen("baklava.in", "r", stdin);

	const int maxn = 800 + 5, maxit = 1e6;
	vector<double> v(maxn, -5);

	int c;
	cin >> c;

	for(; c > 0; --c)
	{
		int n; cin >> n;
		if(v[n] < -3)
		{
			v[n] = 0;

			double f = sinl(2 * acosl(-1) / n) * n / 8 / sinl(acosl(-1) / n);
			double F = 1 - cosl(acosl(-1) * (n - 2) / n);

			double p = 1, aa = 1 / f;
			for(int i = 1; i < maxit; ++i)
			{
				double naa = aa / 2 * F;
				double np = naa * f;

				if(np >= p) break;

				v[n] += 10000 * (p - np) * i;
				p = np;
				aa = naa;
			}
		}

		cout << fixed << setprecision(5) << v[n] << endl;
	}

	return 0;
}