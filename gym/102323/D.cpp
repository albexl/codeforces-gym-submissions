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
	
	int tc;
	cin >> tc;
	
	for(int cases = 1; cases <= tc; cases++){
		
		int c;
		cin >> c;
		
		vector<ll> cars(c), p(4 * c);
		for(int i = 0; i < c; i++)
			cin >> cars[i];
		
		sort(cars.begin(), cars.end());
		
		for(int i = 0; i < 4 * c; i++)
			cin >> p[i];
		
		sort(p.rbegin(), p.rend());
		
		ll ans = 0;
		
		for(int i = 0, j = 0; i < c; i++, j += 4){
			ll mx = max(p[j], p[j + 1]);
			mx = max(mx, p[j + 2]);
			mx = max(mx, p[j + 3]);
			ans = max(ans, cars[i] + mx);
		}
		
		cout << "Trip #" << cases << ": " << ans << endl;
	}
	

	return 0;
}