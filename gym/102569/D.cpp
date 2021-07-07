

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
	
	int n, m;
	cin >> n >> m;
	
	vector<vector<pair<int, int>>> g(n + 1);
	for(int i = 0; i < m; i++){
		int a, b;
		char c;
		cin >> a >> b >> c;
		g[a].push_back({b, c - 'a'});
		g[b].push_back({a, c - 'a'});
	}
	
	vector<int> d(n + 1, -1);
	d[n] = 0;
	queue<int> Q;
	Q.push(n);
	
	while(!Q.empty()){
		int u = Q.front();Q.pop();
		for(auto &e : g[u]){
			int v = e.first;
			if(d[v] == -1){
				d[v] = d[u] + 1;
				Q.push(v);
			}
		}
	}
	
	vector<int> pi(n + 1, -1), opt(n + 1, 1e9), mn(n + 1, 1e9);
	Q.push(1);
	mn[d[1]] = 0;
	opt[1] = 0;
	
	while(!Q.empty()){
		int u = Q.front();Q.pop();
		
		//cerr << u << " :" << endl;
		//cerr << d[u] << " "<< opt[u] << " " << mn[d[u]] << endl;
		
		if(opt[u] != mn[d[u]])
			continue;
		
		for(auto &e : g[u]){
			int v = e.first;
			int c = e.second;
			
			
			
			if(d[v] == d[u] - 1){
				//cerr << v << " " << c << endl;
				if(opt[v] == 1e9)
					Q.push(v);
				mn[d[v]] = min(mn[d[v]], c);
				if(c < opt[v]){
					opt[v] = c;
					pi[v] = u;
				}
			}
		}
	}

	vector<int> path;
	int cur = n;
	while(cur != -1){
		path.push_back(cur);
		cur = pi[cur];
	}
	
	reverse(path.begin(), path.end());
	cout << d[1] << endl;
	for(int i = 0; i < path.size(); i++)
		cout << path[i] << " \n"[i + 1 == path.size()];
	for(int i = 1; i < path.size(); i++)
		cout << (char)(opt[path[i]] + 'a');
	cout << endl;

	return 0;
}