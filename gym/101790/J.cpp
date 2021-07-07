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
	
	cout << setprecision(10) << fixed;
	
	const int maxn = 1e5 + 5;
	
	int n, m;
	
	cin >> n;
	vector<vector<int>> g1(n);
	
	for(int i = 1, a, b; i < n; i++){
		cin >> a >> b;
		a--, b--;
		g1[a].push_back(b);
		g1[b].push_back(a);
	}
	
	cin >> m;
	vector<vector<int>> g2(m);
	
	for(int i = 1, a, b; i < m; i++){
		cin >> a >> b;
		a--, b--;
		g2[a].push_back(b);
		g2[b].push_back(a);
	}
	
	vector<int> d1(n, -1), d2(m, -1);
	
	queue<int> Q;
	for(int i = 0; i < n; i++)
		if(g1[i].size() == 1)
			d1[i] = 0, Q.push(i);
	
	while(!Q.empty()){
		int u = Q.front();Q.pop();
		for(auto &v : g1[u])
			if(d1[v] == -1)
				d1[v] = d1[u] + 1, Q.push(v);
	}
	
	for(int i = 0; i < m; i++)
		if(g2[i].size() == 1)
			d2[i] = 0, Q.push(i);
	
	while(!Q.empty()){
		int u = Q.front();Q.pop();
		for(auto &v : g2[u])
			if(d2[v] == -1)
				d2[v] = d2[u] + 1, Q.push(v);
	}
	
	double ans = 0.0;
	
	vector<int> acum1(maxn), acum2(maxn);
	
	for(int i = 0; i < n; i++)
		acum1[d1[i]]++;

	for(int i = 0; i < m; i++)
		acum2[d2[i]]++;
	
	for(int i = maxn - 2; i >= 0; i--){
		acum1[i] += acum1[i + 1];
		acum2[i] += acum2[i + 1];
	}

	for(int i = 0; i < max(n, m); i++){
		
		//cout << i << ":" << endl;
		
		//both
		//cout << acum1[i] - acum1[i + 1] << " " << acum2[i] - acum2[i + 1] << endl;
		double p1 = 1.0 * (acum1[i] - acum1[i + 1]) / n;
		double p2 = 1.0 * (acum2[i] - acum2[i + 1]) / m;
		ans += 1.0 * p1 * p2 * i;
		
		//just 1
		//cout << acum1[i] - acum1[i + 1] << " " << acum2[i + 1] << endl;
		p1 = 1.0 * (acum1[i] - acum1[i + 1]) / n;
		p2 = 1.0 * (acum2[i + 1]) / m;
		ans += 1.0 * p1 * p2 * i;
		
		//just 2
		//cout << acum1[i + 1] << " " << acum2[i] - acum2[i + 1] << endl;
		p1 = 1.0 * (acum1[i + 1]) / n;
		p2 = 1.0 * (acum2[i] - acum2[i + 1]) / m;
		ans += 1.0 * p1 * p2 * i;
		
	}
	
	cout << ans << endl;

	return 0;
}