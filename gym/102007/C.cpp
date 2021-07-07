#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	ll n;
	cin >> n;

	ll ans = 0x3f3f3f3f3f3f3f3f;
	for(ll a = 1; a <= n; ++a)
	{
		if(a * a * a > n) break;

		for(ll b = a; b <= n; ++b)
		{
			if(a * b * b > n) break;
			if(n % (a * b) != 0) continue;

			ll c = n / (a * b);
			ans = min(ans, 2 * (a * c + a * b + b * c));
		}
	}

	cout << ans << endl;

	return 0;
}