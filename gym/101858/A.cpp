#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;
//typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	const ll mod = 1e9 + 7;
	
	ll n;
	cin >> n;
	
	if(n % 2)
		cout << 0 << endl;
	else{
		ll ans = 1, sum = 1;
		for(ll i = 2; i <= n; i += 2){
			ans = (ans + 2LL * sum) % mod;
			sum = (sum + ans) % mod;
		}
		cout << ans << endl;
	}

	return 0;
}