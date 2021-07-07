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
	
	const ll oo = 1e16;
	
	int t;
	cin >> t;
	
	for(int cases = 1; cases <= t; cases++){
		cout << "Case #" << cases << ": ";
		
		int n, m;
		cin >> n >> m;
		
		int k;
		cin >> k;
		
		int s = 0;
		while(k--){
			int x;
			cin >> x;
			s |= (1 << x);
		}
		
		int t = 0;
		cin >> k;
		while(k--){
			int x;
			cin >> x;
			t |= (1 << x);
		}
		
		vector<ll> d(1 << n, oo);
		d[s] = 0;
		
		vector<pair<ll, pii>> rules(m);
		
		for(int i = 0; i < m; i++){
			ll cost;
			cin >> cost;
			
			int s1 = 0, s2 = 0;
			
			cin >> k;
			while(k--){
				int x;
				cin >> x;
				s1 |= (1 << x);
			}
			
			cin >> k;
			while(k--){
				int x;
				cin >> x;
				s2 |= (1 << x);
			}
			
			rules[i] = {cost, {s1, s2}};
		}
		
		priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
		pq.push({0, s});
		while(!pq.empty()){
			int u = pq.top().second;
			ll w = pq.top().first;
			pq.pop();
			
			if(w != d[u])
				continue;
			
			for(auto &el : rules){
				ll c = el.first;
				int a = el.second.first;
				int b = el.second.second;
				
				bool ok = (u & a) == a;
				
				if(ok){
					int v = (u ^ a) | b;
					
					if(d[v] > d[u] + c){
						d[v] = d[u] + c;
						pq.push({d[v], v});
					}
					
				}
			}
		}
		
		if(d[t] == oo)
			cout << "NO" << endl;
		else
			cout << "YES " << d[t] << endl;
	}

	return 0;
}