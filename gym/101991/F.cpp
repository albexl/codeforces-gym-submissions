#include <bits/stdc++.h>

using namespace std;

//#define endl '\n'
//#define double long double

typedef long long ll;
typedef pair<double, double> pii;

const int maxk = 300 + 5;
double fac[maxk];

void init()
{
	fac[0] = 0;
	for(int i = 1; i < maxk; ++i)
		fac[i] = fac[i - 1] + log(i);
}

double nk_log(int n, int k)
{
	return fac[n] - fac[k] - fac[n - k];
}

int v[maxk][maxk];
char buff[maxk + maxk + maxk];

//double dp[maxk][maxk];

int main()
{
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);

	freopen("fetiera.in", "r", stdin);

	init();

	int c;
	scanf("%d", &c);

	for(; c > 0; --c)
	{
		int n, K;
		scanf("%d %d\n", &n, &K);
//		cin >> n >> K;

		ll t = 0;
		for(int i = 0; i < n; ++i)
		{
			scanf("%[^\n]\n", buff);
			for(int j = 0, it = 0; j < n; ++j, it += 2)
			{
				v[i][j] = buff[it] == '1';
				t += (n - i) * (n - j);
//				cin >> v[i][j], t += (ll) (n - i) * (n - j);
			}
		}

		map<ll, pii> M;

		double ans = 0, Klogt = K * log(t);
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j)
			{
				ll s = (ll)(i + 1) * (j + 1) * (n - i) * (n - j);
				if(M.find(s) != M.end())
				{
					if(v[i][j] == 1)
						ans += M[s].first;
					else
						ans += M[s].second;
					continue;
				}

				if(t == s)
				{
					if((K % 2 == 0 && v[i][j] == 1) || (K % 2 == 1 && v[i][j] == 0))
						++ans;
					continue;
				}

//				printf("%lld ", s);
//				if(j + 1 == n) printf("\n");

				double p = 0, ip = 0, logs = log(s), logr = log(t - s);
				for(int k = 0; k <= K; ++k)
				{
					double med = nk_log(K, k) + k * logs + (K - k) * logr - Klogt;
					if(k & 1)
						ip += exp(med);
					else
						p += exp(med);
				}

				M[s] = {p, ip};
				if(v[i][j] == 1)
					ans += p;
				else
					ans += ip;
			}

		printf("%.5lf\n", ans);
//		cout << fixed << setprecision(5) << ans << endl;
	}

	return 0;
}