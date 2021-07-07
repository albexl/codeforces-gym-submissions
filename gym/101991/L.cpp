#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	freopen("looking.in", "r", stdin);

	ll t;
	cin >> t;
	while(t--){
		ll n, k;
		cin >> n >> k;

		ll ans = 0;

		for(ll i = 0, x; i < n; i++)
			cin >> x, ans |= x;

		cout << ans << endl;
	}

	return 0;
}