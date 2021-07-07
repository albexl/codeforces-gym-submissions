#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'


typedef long long ll;
typedef pair<ll, ll> pii;

 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	ll n, k;
	cin >> n >> k;

	ll cnt = n / k;

	ll ans = cnt;
	
	if(n % k){
		ans++;

		ll rem = n % k;

		ll am = cnt * k;

		ll tricky = min(k - rem, am);

		n -= tricky;
		n = max(0ll, n);
	}

	ans += n / k + (n % k != 0);

	cout << ans << endl;

	

	return 0;
}