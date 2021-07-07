#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;
//typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;

const int maxn = 5e3 + 5;
const ll mod = 1e9 + 7;

ll mod_exp(ll a, ll b){
	if(b == 0) return 1;
	if(b % 2 == 0){
		ll t = mod_exp(a, b >> 1LL) % mod;
		return t * t % mod;
	}
	return a * mod_exp(a, b - 1) % mod;
}

ll inv(ll x){
	return mod_exp(x, mod - 2) % mod;
}

ll dp[maxn][maxn], p[26];
string a;
int n, m;

ll solve(int pos, int pref){
	if(pos == n)
		return pref == m ? 1 : 0;
	if(pref == m)
		return 1;
	if(dp[pos][pref] != -1)
		return dp[pos][pref];
	ll ans = 0;
	for(int i = 0; i < 26; i++){
		if(i == a[pref] - 'a')
			ans = (ans + p[i] * solve(pos + 1, pref + 1)) % mod;
		else
			ans = (ans + p[i] * solve(pos + 1, pref)) % mod;
	}
	return dp[pos][pref] = ans;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	cin >> n >> m >> a;
	
	for(int i = 0; i < 26; i++){
		ll x, y;
		cin >> x >> y;
		p[i] = x * inv(y) % mod;
	}
	
	memset(dp, -1, sizeof(dp));
	cout << solve(0, 0) << endl;
	
	return 0;
}