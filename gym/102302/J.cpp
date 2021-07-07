#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define MAX

typedef long long ll;
typedef pair<ll, int> pii;
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

const ll oo = 0x3f3f3f3f3f3f3f3f;

bool is_prime(ll x){
	if(x <= 1)
		return false;

	for(ll i = 2; i * i <= x; i++)
		if(x % i == 0)
			return false;

	return true;
}

ll calc(ll x, vector<ll> &v){

	ll ans = 0;
	for(auto &val : v)
		ans += abs(val - x);
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);


	int n;
	cin >> n;

	vector<ll> v(n);

	for(int i = 0; i < n; i++)
		cin >> v[i];

	sort(v.begin(), v.end());

	ll m = v[n / 2];

	ll ans = oo;

	ll x = m;
	while(!is_prime(x)){
		x++;
	}

	ans = min(ans, calc(x, v));

	x = m;

	if(x >= 2){
		while(!is_prime(x)){
			x--;
		}
		ans = min(ans, calc(x, v));
	}

	cout << ans << endl;


	return 0;
}