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
	
	int tc;
	cin >> tc;
	
	for(int cases = 1; cases <= tc; cases++){
		
		cout << "Strategy #" << cases << ": ";
		
		int n, q;
		cin >> n >> q;
		
		vector<bool> rows(n + 1, true), cols(n + 1, true);
		
		int ans = 0;
		while(q--){
			int x, y;
			cin >> x >> y;
			
			if(!rows[x] && !cols[y])
				ans++;
			else
				rows[x] = cols[y] = false;
		}
		
		cout << ans << endl;
		cout << endl;
	}

	return 0;
}