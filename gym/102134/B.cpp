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
	
	ll a, b;
	cin >> a >> b;
	
	ll num = a;
	
	vector<ll> v;
	string ans = "";
	
	while(num > 1){
		ll p = 1;
		while(p <= num){
			p *= 2ll;
		}
		v.push_back(num);
		num = p - num;
	}
	
	v.push_back(1);
	
	reverse(v.begin(), v.end());
	
	ll cnt = 0;
	
	for(int i = 0; i < (int)v.size(); i++){
		while( (1ll << cnt) <= v[i]){
			ans += "0";
			cnt++;
		}
		if(i)
			ans += "1";
	}
	
	while(cnt < b)
		ans += "0", cnt++;
	
	cout << ans << endl;

	return 0;
}