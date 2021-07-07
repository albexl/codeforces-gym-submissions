#include<bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

#define endl '\n'
#define MAX

typedef long long ll;
typedef pair<int,int> pii;
//typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;

const ll mod = 1e9 + 9;

ll k, b;

ll Solve(vector<ll> &pows, ll rem){
	vector<ll> dp(k);
	dp[0] = 1;
	
	for(auto &p : pows){
		vector<ll> upd(k);
		
		for(ll i = 0; i < k; i++){
			ll n_rem = (p + i) % k;
			upd[n_rem] += dp[i];
			upd[n_rem] %= mod;
		}
		
		for(ll i = 0; i < k; i++){
			dp[i] += upd[i];
			dp[i] %= mod;
		}
		
	}
	
	return dp[rem];
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	
	cin >> k >> b;
	vector<ll> pows(b);
	
	pows[0] = 1 % k;
	for(ll i = 1; i < b; i++)
		pows[i] = (pows[i - 1] * 2LL) % k;
	
	ll ans = 0;
	
	for(ll i = 0; i < b; i++){
		vector<ll> aux;
		for(ll j = 0; j < b; j++)
			if(j != i)
				aux.push_back(pows[j]);
		ans += Solve(aux, (k - pows[i]) % k);
		ans %= mod;
	}
	
	cout << ans << endl;

	return 0;
}