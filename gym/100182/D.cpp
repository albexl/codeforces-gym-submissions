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


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	//mt19937 rng(5);
	//srand(time(0));
	
	while(true){
		ll n, m, k;
		cin >> n >> m >> k;
		
		if(n == 0)
			break;
		
		vector<ll> v(k);
		for(int i = 0; i < k; i++)
			cin >> v[i];
		
		ll ans = 0, cur = n;
		ll pos = 0;
		while(m--){
			ans += cur;
			cur += v[pos];
			pos = (pos + 1) % k;
		}
		
		cout << ans << endl;
	}

	

	return 0;
}