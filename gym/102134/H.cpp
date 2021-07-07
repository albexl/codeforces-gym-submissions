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
	
	int n;
	cin >> n;
		
	vector<int> b(22), x(n);
	for(int i = 0; i < n; i++){
		cin >> x[i];
		for(int j = 0; j < 22; j++)
			if(x[i] & (1 << j))
				b[j]++;
	}
	

	ll ans = 0;

	for(int bt = 0; bt < 22; bt++){
		ll c = 1ll * b[bt];
		ll cn = 1ll * n - c;	
		ans += (1ll << bt) * c;//1
		ans += (1ll << bt) * c * (c - 1) * 3ll;//2
		ans += (1ll << bt) * c * cn * 3ll;//2
		ans += (1ll << bt) * c * cn * (cn - 1) * 3ll;//3
		ans += (1ll << bt) * c * (c - 1) * (c - 2);//3;
	}

	cout << ans << endl;

	return 0;
}