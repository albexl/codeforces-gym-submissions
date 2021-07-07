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

const int maxn = 1000 + 5;
const ll mod = 1e9 + 7;

ll f[maxn];

ll mod_exp(ll a, ll b){
	if(b == 0)return 1;
	if(b % 2 == 0){
		ll t = mod_exp(a, b >> 1);
		return t * t % mod;
	}
	return a * mod_exp(a, b - 1) % mod;
}

ll inv(ll x){
	return mod_exp(x, mod - 2) % mod;
}

ll n_k(ll n, ll k){
	
	if(k > n || n < 0 || k < 0)
		return 0;
		
	ll num = f[n];
	ll den = f[k];
	
	den = (den * f[n - k]) % mod;
	den = inv(den);
	
	return num * den % mod;
}



int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	f[0] = 1ll;
	
	for(int i = 1; i < maxn; i++)
		f[i] = 1ll * i * f[i - 1] % mod;
	
	
	int n, m;
	cin >> n >> m;
	
	vector<vector<bool>> G(n + 1, vector<bool>(n + 1));
	
	for(int i = 0, a, b; i < m; i++){
		cin >> a >> b;
		G[a][b] = G[b][a] = true;
	}
	
	ll ans = 0;
	
	for(int u = 1; u <= n; u++){
		for(int v = 1; v <= n; v++){
			if(u != v && G[u][v]){
				
				ll up = 0, down = 0, both = 0;
				
				for(int k = 1; k <= n; k++){
					if(k != v && k != u){
						if(G[k][v] && G[k][u])
							both++;
						if(G[k][u] && !G[k][v])
							up++;
						if(G[k][v] && !G[k][u])
							down++;
					}
				}
				
				//3
				ll cnt = n_k(up, 3);
				cnt *= n_k(down + both, 2);
				cnt %= mod;
				
				ans += cnt;
				ans %= mod;
				
				//2
				cnt = n_k(up, 2);
				cnt *= n_k(both, 1);
				cnt %= mod;
				cnt *= n_k(down + both - 1, 2);
				cnt %= mod;
				
				ans += cnt;
				ans %= mod;
				
				//1
				cnt = n_k(up, 1);
				cnt *= n_k(both, 2);
				cnt %= mod;
				cnt *= n_k(down + both - 2, 2);
				cnt %= mod;
				
				ans += cnt;
				ans %= mod;
				
				//0
				cnt = n_k(both, 3);
				cnt *= n_k(down + both - 3, 2);
				cnt %= mod;
				
				ans += cnt;
				ans %= mod;
				
			}
		}
	}
	
	cout << ans << endl;

	return 0;
}