#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	ll a, b, c, d;
	cin >> a >> b >> c >> d;

	ll cnt = 0;
	for(int i = 1; i <= 1000; ++i)
		for(int j = 1; j + i < 1000; ++j)
			if(__gcd(i, j) == 1)
			{
				ll x = max((a + j - 1) / j, (c + i - 1) / i);
				ll y = min(b / j, d / i);
				if(x <= y)
					cnt += y - x + 1;
			}

	cout << cnt << endl;

	return 0;
}