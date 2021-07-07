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
//typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;

//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

bool prime(ll x){
	for(ll i = 2; i * i <= x; i++)
		if(x % i == 0)
			return false;
	return true;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	int t;
	cin >> t;
	
	int cases = 1;
	
	while(t--){
		ll n;
		cin >> n;
		
		ll ans = 0;
		if(n == 1)
			ans = 1;
		else if(prime(n)){
			ans = 1;
			for(ll i = 1; i <= n - 1; i++){
				ans *= 2;
				ans %= n;
			}
		}
		else{
			ans = (n - 1) * (n - 1) % n;
		}
		
		cout << "Case #" << cases++ << ": " << ans << endl; 
	}

	return 0;
}