#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <random>
#include <chrono>

using namespace std;
using namespace __gnu_pbds;

//#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;
//typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;

//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

bool ok(int x, int y, int k){
	for(int i = 0; i < k; i++){
		int b1 = (x & (1 << i)) != 0;
		int b2 = (y & (1 << i)) != 0;
		
		if(b1 != b2)
			return false;
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	int n;
	cin >> n;

	int maxb = (int)log2(n);
	int mask = 0;
	
	vector<int> cands;
	for(int i = 1; i <= n; i++)
		cands.push_back(i);
	
	for(int k = 0; k <= maxb; k++){
		
		//for(int i = 0; i < cands.size(); i++)
		//	cout << cands[i] << " \n"[i + 1 == cands.size()];
		//cout << endl;
		//cout << endl;
		
		
		int z = 0, o = 0;
		for(int j = 0; j <= n; j++){
			
			if(k == 0){
				if(j & (1 << k))
					o++;
				else
					z++;
			}
			else{
				if(ok(j, mask, k)){
					if(j & (1 << k))
						o++;
					else
						z++;
				}
			}
		}
		
		vector<pii> cur;
		
		int on = 0, off = 0;
		
		for(auto &x : cands){
			
			cout << "? " << x << " " << k << endl;
			int ans;
			cin >> ans;
			
			cur.push_back({x, ans});
			
			if(ans == 1)
				on++;
			else
				off++;
		}
		
		//cout << o << " " << z << " " << on << " " << off << endl;
		
		cands.clear();
		
		int target = 0;
		
		if(on != o){
			mask |= (1 << k);
			target = 1;
		}
	
		for(auto &x : cur){
			int idx = x.first;
			int bit = x.second;
			if(bit == target)
				cands.push_back(idx);
		}
	
	}
	
	cout << "! " << mask << endl;

	return 0;
}