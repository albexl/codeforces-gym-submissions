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
	
	int r, n;
	ll k;
	
	cin >> r >> k >> n;
	
	vector<ll> v(n + n + 5), sum(n + n + 5);
	
	for(int i = 1; i <= n; i++){
		cin >> v[i];
		v[i + n] = v[i];
	}
	
	for(int i = 1; i < v.size(); i++)
		sum[i] = sum[i - 1] + v[i];
	
	vector<int> pos(n + n, -1);
	
	for(int i = 1; i <= n; i++){
		for(int j = i; j - i + 1 <= n; j++){
			ll s = sum[j] - sum[i - 1];
			if(s <= k)
				pos[i] = j;
		}
	}
	
	ll ans = 0;
	int cur = 1;
	
	while(r--){
		int nxt = pos[cur];
		
		//cout << cur << " " << nxt << " " << sum[nxt] - sum[cur - 1] << endl;
		
		ans += sum[nxt] - sum[cur - 1];
		cur = nxt + 1;
		if(cur > n)
			cur -= n;
	}
	
	cout << ans << endl;

	return 0;
}