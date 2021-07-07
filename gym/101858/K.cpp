#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define endl '\n'

typedef long long ll;
typedef pair<ll, ll> pii;
typedef pair<ll, pii> tri;
//typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;

const ll maxn = 1e5 + 5;
const ll oo = 0x3f3f3f3f3f3f3f3f;

ll dp[maxn][3], n, m;
vector<pii> g[maxn];

void dijkstra(){
	
	for(ll i = 1; i <= n; i++)
		for(ll j = 0; j < 3; j++)
			dp[i][j] = oo;
	
	dp[1][0] = 0;
	priority_queue<tri, vector<tri>, greater<tri>> Q;
	Q.push({0, {1, 0}});
	
	while(!Q.empty()){
		ll dist = Q.top().first;
		ll x = Q.top().second.first;
		ll y = Q.top().second.second;
		Q.pop();
		
		if(dist != dp[x][y])
			continue;
		
		if(x == n)
			continue;
			
		for(auto &e : g[x]){
			ll v = e.first;
			ll c = e.second;
			
			if(dp[v][(y + 1) % 3] > dp[x][y] + c){
				dp[v][(y + 1) % 3] = dp[x][y] + c;
				Q.push({dp[v][(y + 1) % 3], {v, (y + 1) % 3}});
			}
		}
	}
	
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	cin >> n >> m;
	
	for(ll i = 0, a, b, c; i < m; i++){
		cin >> a >> b >> c;
		g[a].push_back({b, c});
		g[b].push_back({a, c});
	}
	
	dijkstra();
	
	vector<pair<ll, string>> ans;
	
	ans.push_back({dp[n][0], "me"});
	ans.push_back({dp[n][1], "Gon"});
	ans.push_back({dp[n][2], "Killua"});
	
	sort(ans.begin(), ans.end());
	for(auto &e : ans)
		cout << e.second << endl;
	
	return 0;
}