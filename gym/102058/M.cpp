#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;
const ll oo = 0x3f3f3f3f3f3f3f3f;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	ll n, k, a;
	cin >> n >> k >> a;

	ll mn = oo;
	for(int i = 0, t, s; i < n; ++i)
	{
		cin >> t >> s;
		ll tt = t*a;
		ll t2 = k / tt;
		ll t3 = k % tt;

		ll sum = t2 * t;
		sum += t2 * s;

		if(t3 == 0) sum -= s;
		else
		{
			sum += (t3 + a - 1) / a;
		}


		mn = min(mn, sum);

	}

	cout << mn << endl;


}