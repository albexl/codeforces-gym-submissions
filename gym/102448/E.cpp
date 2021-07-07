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

int sum(int x){
	int ans = 0;
	for(int i = 1; 1ll * i * i <= x; i++){
		if(x % i == 0){
			ans += i;
			if(x / i != i)
				ans += x / i;
		}
	}
	ans -= x;
	return ans;
}


vector<int> perf = {6, 28, 496, 8128};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		
		int ans = -1;
		for(auto &x : perf)
			if(x <= n)
				ans = x;
		
		cout << ans << endl;
	}

	return 0;
}