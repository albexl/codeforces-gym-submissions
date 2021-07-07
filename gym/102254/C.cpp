#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	const ll oo = 0x3f3f3f3f3f3f3f3f;

	int n;
	ll x, d;
	cin >> n >> x >> d;

	vector<ll> v(n);

	for(int i = 0; i < n; i++)
		cin >> v[i];

	ll ans = 0;

	for(int i = 1; i < (1 << n); i++){
		ll sum = 0;
		ll mn = oo;
		ll mx = -1;

		for(int j = 0; j < n; j++){
			if(i & (1 << j)){
				sum += v[j];
				mn = min(mn, v[j]);
				mx = max(mx, v[j]);
			}
		}

		if(sum >= x && mx - mn <= d)
			ans++;
	}

	cout << ans << endl;

	return 0;
}