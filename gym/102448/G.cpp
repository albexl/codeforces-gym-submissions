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
	
	int n, m, k;
	cin >> n >> m >> k;
	
	map<string, int> mp;
	vector<ll> v(n);
	vector<string> name(n);
	
	for(int i = 0; i < n; i++){
		cin >> name[i];
		mp[name[i]] = i;
	}
	
	map<string, ll> probs;
	
	for(int i = 0; i < m; i++){
		string s;
		ll x;
		cin >> s >> x;
		probs[s] = x;
	}
	
	while(k--){
		string handle, prob, verd;
		cin >> handle >> prob >> verd;
		if(verd == "AC")
			v[mp[handle]] += probs[prob];
	}
	
	for(int i = 0; i < n; i++)
		cout << name[i] << " " << v[i] << endl;
	

	return 0;
}