#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;

map<string, int> trans;
const int oo = 2e9;

int solve(){
	
	int n;
	cin >> n;
	
	map<string, int> mp;
	vector<int> cost(n);
	
	vector<vector<pii> > g(4 * n);
	
	for(int i = 0; i < n; i++){
		string s;
		cin >> s >> cost[i];
		mp[s] = i * 4;
	}
	
	for(int i = 0; i < 4 * n; i += 4){
		for(int j = i; j < i + 4; j++)
			for(int k = j + 1; k < i + 4; k++){
				g[j].push_back({k, cost[i / 4]});
				g[k].push_back({j, cost[i / 4]});
			}
	}
	
	int m;
	cin >> m;
	
	while(m--){
		string a, b, method;
		int w;
		cin >> a >> b >> method >> w;
		int x = mp[a], y = mp[b], add = trans[method];
		g[x + add].push_back({y + add, w});
		g[y + add].push_back({x + add, w});
	}
	
	string a, b;
	cin >> a >> b;
	
	int s = mp[a], t = mp[b];
	
	priority_queue<pii, vector<pii>, greater<pii> > pq;
	vector<int> d(4 * n, oo);
	for(int i = 0; i < 4; i++){
		d[s + i] = 0;
		pq.push({0, s + i});
	}
	
	while(!pq.empty()){
		int u = pq.top().second;
		int w = pq.top().first;
		pq.pop();
		
		if(w != d[u])
			continue;
		
		for(auto &e : g[u]){
			int v = e.first;
			int cost = e.second;
			if(d[v] > d[u] + cost){
				d[v] = d[u] + cost;
				pq.push({d[v], v});
			}
		}
	}
	
	int ans = oo;
	for(int i = 0; i < 4; i++)
		ans = min(ans, d[t + i]);
	return ans;
}


int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	trans["AIR"] = 0;
	trans["SEA"] = 1;
	trans["RAIL"] = 2;
	trans["TRUCK"] = 3;
	
	int t;
	cin >> t;
	
	while(t--){
		cout << solve() << endl;
	}


	return 0;
}