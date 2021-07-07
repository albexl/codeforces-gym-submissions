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

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	ll n, k;
	cin >> n >> k;
	
	k += k;
	
	ll cnt = n / k + (n % k != 0);
	ll ans = cnt * 5;
	
	if(n % k != 0){
		
		ll rem = k - n % k;
		n -= rem;
	}
	
	cnt = n / k + (n % k != 0);
	ans += cnt * 5;

	cout << ans << endl;

	return 0;
}