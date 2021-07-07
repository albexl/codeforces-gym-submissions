#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <random>
#include <chrono>
 
using namespace std;
using namespace __gnu_pbds;
 
#define endl '\n'
 
typedef long long ll;
typedef pair<int, int> pii;
typedef tree<int, null_type,less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
template<typename T>
static T randint(T lo, T hi){
	return uniform_int_distribution<T>(lo, hi)(rng);
}

bool is_leap(ll x){
	if(x % 100 == 0)
		return x % 400 == 0;
	return x % 4 == 0;
}
//					   1   2   3   4   5   6   7   8   9   10   11  12
vector<ll> days = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30,  31,  30, 31};

vector<ll> get(ll x){
	vector<ll> ans;
	while(x){
		ans.push_back(x % 10);
		x /= 10;
	}

	reverse(ans.begin(), ans.end());
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	// cout << is_leap(4) << endl;
	// cout << is_leap(1900) << endl;
	// cout << is_leap(2000) << endl;

	// return 0;

	ll a, b;
	cin >> a >> b;

	ll cost = 0;

	for(ll i = 1; i <= 12; i++){
		for(ll j = 1; j <= days[i]; j++){
			auto v1 = get(i), v2 = get(j);
			ll num = 0;

			for(auto &x : v1)
				num = num * 10 + x;
			for(auto &x : v2)
				num = num * 10 + x;
			cost += num;
		}
	}

	ll ans = cost * (b - a + 1);

	ll x = a;
	while(x <= b && !is_leap(x)){
		x++;
	}

	if(x <= b){
		ll cnt = (b - x) / 4;
		ans += cnt * 229;
	}
	
	cout << ans << endl;

	return 0;
}