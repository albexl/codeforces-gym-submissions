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
	
	const int maxn = 1e5 + 5;
	vector<ll> ans(maxn);
	
	ans[1] = ans[2] = 0;
	for(int i = 3; i < maxn; i++){
		ans[i] = ans[i - 1];
		if(i == 3)
			ans[i] += 2;
		else if(i % 3 == 1 || i % 3 == 0)
			ans[i] += 1;
	}
	
	
	int q;
	cin >> q;
	while(q--){
		int pos;
		cin >> pos;
		cout << ans[pos] << endl;
	}
	
	

	return 0;
}