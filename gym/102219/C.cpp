#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<ll, ll> pii;



int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	const ll oo = 1e15;

	int tc;
	cin >> tc;

	for(int cases = 1; cases <= tc; cases++){

		ll n, s;
		cin >> n >> s;

		vector<pii> a, b;

		for(int i = 0; i < n; i++){
			ll x, y;
			cin >> x >> y;
			if(y <= s)
				a.push_back({x, y});
			else
				b.push_back({x, y});
		}

		ll ans = -oo;
			
		if(!a.empty()){
			for(auto &val : a)
				ans = max(ans, val.first);
		}
		else{
			for(auto &val : b)
				ans = max(ans, val.first - val.second + s);
		}

		cout << "Case #" << cases << ": " << ans << endl;

	}
	

	return 0;
}