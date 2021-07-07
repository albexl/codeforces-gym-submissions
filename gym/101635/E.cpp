#include<bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

#define endl '\n'
#define MAX

typedef long long ll;
typedef pair<ll,ll> pii;
//typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;

const int maxn = 10000 + 5;
const ll oo = 10000000000000LL;

ll dp[2][maxn];
ll opt[2][maxn];
ll idx = 1;
map<string,ll> M;
vector<pair<ll,pii>> g[maxn];
ll in_degree[maxn];
ll C[maxn],P[maxn];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	ll b, n;
	cin >> b >> n;
	for(int i = 0; i < n; i++){
		string a, b, c;
		ll p, cost;
		cin >> a >> b >> c >> cost >> p;
		if(M.find(a) == M.end())
			M[a] = idx++;
		if(M.find(b) == M.end())
			M[b] = idx++;
		ll n1 = M[a];
		ll n2 = M[b];
		in_degree[n1]++;
		g[n2].push_back({n1, {p, cost}});
	}

	for(int i = 1; i < idx; i++)
		C[i] = oo;
	
	queue<ll> Q;
	for(int i = 1; i < idx; i++)
		if(in_degree[i] == 0){
			Q.push(i);
			C[i] = 0;
		}
	

	while(!Q.empty()){
		ll x = Q.front();Q.pop();
		for(auto y : g[x]){
			ll adj = y.first;
			ll p = y.second.first + P[x];
			ll c = y.second.second + C[x];
			in_degree[adj]--;
			if(C[adj] > c){
				C[adj] = c;
				P[adj] = p;
			}
			else if(C[adj] == c && P[adj] < p )
				P[adj] = p;
			if(in_degree[adj] == 0)
				Q.push(adj);
		}
	}
	
	ll s1 = 0,s2 = 0;
	
	for(int i = 1; i < idx; i++){
		for(int j = 0; j <= b; j++){
			
			dp[i % 2][j] = dp[(i + 1) % 2][j];
			opt[i % 2][j] = opt[(i + 1) % 2][j];
			
			if(j - C[i] >= 0){
				ll n_value = dp[(i + 1) % 2][j - C[i]] + P[i];
				ll n_cost = opt[(i + 1) % 2][j - C[i]] + C[i];
				if(dp[i % 2][j] < n_value){
					dp[i % 2][j] = n_value;
					opt[i % 2][j] = n_cost;
				}
				else if(dp[i % 2][j] == n_value && opt[i % 2][j] > n_cost)
					opt[i % 2][j] = n_cost;
			}
		}
	}
	
	for(int j = 0; j <= b; j++){
		ll n_value = dp[(idx + 1) % 2][j];
		ll n_cost = opt[(idx + 1) % 2][j];
		if(n_value > s1){
			s1 = n_value;
			s2 = n_cost;
		}
		else if(n_value == s1 && n_cost < s2)
			s2 = n_cost;
	}
	
	
	cout << s1 << endl << s2 << endl;
		

	return 0;
}