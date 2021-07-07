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

	const int maxn = 2e5 + 5;

	int n;
	cin >> n;
	
	vector<vector<pii>> blocks(maxn);
	vector<int> v(n + 1, maxn), cnt(maxn);
	
	for(int i = 0; i < n; i++)
		cin >> v[i];

	int lo = 0, total = 0;
	for(int i = 1; i < n + 1; i++){
		if(v[i] != v[i - 1]){
			blocks[v[i - 1]].push_back({lo, i - 1});
			lo = i;
			total++;
			cnt[v[i - 1]]++;
		}
	}
	
	int opt = -1, ans = -1;
	
	for(int i = 1; i <= 200000; i++){
		
		if(blocks[i].empty())
			continue;
		
		int amount = total;
		amount -= cnt[i];
		
		for(auto &b : blocks[i]){
			
			
			int l = b.first - 1;
			int r = b.second + 1;
			
			//cout << i << " " << l + 1 << " " << r - 1 << endl;
			
			
			if(l >= 0 && r < n && v[l] == v[r])
				amount--;
		}
		
		if(amount > ans){
			ans = amount;
			opt = i;
		}
	}
	
	cout << ans << " " << opt << endl;

	return 0;
}