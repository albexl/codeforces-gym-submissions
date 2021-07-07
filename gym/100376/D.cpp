#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <random>
#include <chrono>

using namespace std;
using namespace __gnu_pbds;

#define endl '\n'

typedef long long ll;
typedef pair<int, ll> pii;
//typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;

//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 1000 + 5;
const ll oo = 0x3f3f3f3f3f3f3f3f;

vector<pii> g[maxn];
ll d[maxn], n, k, sub[maxn];

priority_queue<ll, vector<ll>, greater<ll>> pq;
ll sum = 0;

void dfs(int v, int p){
	
	//cout << v << " " << p << endl;
	
	sub[v] = d[v];
	for(auto &u : g[v]){
		if(u.first != p){
			dfs(u.first, v);
			sub[v] += sub[u.first];
			sum += u.second * sub[u.first];
			pq.push(u.second * sub[u.first]);
			if((ll)pq.size() > k)
				pq.pop();
		}
	}
	
	//cout << sub[v] << endl;
	
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	cin >> n >> k;
	
	for(int i = 1; i <= n; i++)
		cin >> d[i];
	
	for(int i = 0, a, b; i + 1 < n; i++){
		ll c;
		cin >> a >> b >> c;
		g[a].push_back({b, c});
		g[b].push_back({a, c});
	}
	
	ll solve = oo;
	
	for(int i = 1; i <= n; i++){
		sum = 0;
		dfs(i, -1);
		
		while(!pq.empty()){
			sum -= pq.top();
			pq.pop();
		}
		solve = min(solve, sum);
	}

	cout << solve << endl;

	return 0;
}