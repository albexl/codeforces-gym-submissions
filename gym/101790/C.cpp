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

	int n, k;
	cin >> n >> k;
	
	vector<int> v(n), idx(n + 1);
	vector<vector<int>> pos(n + 1);
	
	for(int i = 0; i < n; i++){
		cin >> v[i];
		pos[v[i]].push_back(i);
	}
	
	for(int i = 1; i <= n; i++)
		pos[i].push_back(n + 5);
	
	int ans = 0;
	set<pii> s;
	set<int> on;
	
	for(int i = 0; i < n; i++){
		if(on.find(v[i]) != on.end()){
			s.erase(s.find(pii(i, v[i])));
			idx[v[i]]++;
			s.insert(pii(pos[v[i]][idx[v[i]]], v[i]));
			continue;
		}
			
		if(on.size() < k){
			ans++;
			on.insert(v[i]);
			idx[v[i]]++;
			s.insert(pii(pos[v[i]][idx[v[i]]], v[i]));
		}
		else{
			ans++;
			auto val = *(s.rbegin());
			int x = val.second;
			on.erase(x);
			s.erase(val);
			on.insert(v[i]);
			idx[v[i]]++;
			s.insert(pii(pos[v[i]][idx[v[i]]], v[i]));
		}
	}
	
	cout << ans << endl;

	return 0;
}