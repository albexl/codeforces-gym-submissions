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
	
	int q;
	cin >> q;
	while(q--){
		ll s;
		cin >> s;
		ll lo = 0, hi = 2e9;
		ll ans = -1;
		while(lo <= hi){
			ll mid = (lo + hi) >> 1LL;
			ll sum = mid * (mid + 1) >> 1LL;
			if(sum <= s){
				ans = mid;
				lo = mid + 1;
			}
			else hi = mid - 1;
		}
		cout << ans << endl;
	}

	return 0;
}