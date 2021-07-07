#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;

ll fast_pow(ll a, ll b, ll mod)
{
	if(!b) return 1;
	ll l = fast_pow(a, b >> 1, mod);
	l = l * l % mod;
	if(b & 1) l = l * a % mod;
	return l;
}

const int maxn = 100;
const ll mod = 1e9 + 7;
ll fac[maxn], ifac[maxn];

ll calc(ll a, ll b)
{
	if(a - 1 - b < 0 || a < 0) return 0;
	return fac[a - 1] * ifac[a - 1 - b] % mod;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	fac[0] = ifac[0] = 1;
	for(int i = 1; i < maxn; ++i)
		fac[i] = fac[i - 1] * i % mod, ifac[i] = fast_pow(fac[i], mod - 2, mod);

	int n;
	cin >> n;

	while(n--)
	{
		int a, b; cin >> a >> b;
		cout << calc(b, a) << endl;
	}

	return 0;
}