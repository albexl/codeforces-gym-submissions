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
	
	int n;
	cin >> n;
	
	vector<pii> segs;
	
	for(int i = 0, xo, yo, xi, yi, xii, yii; i < n; i++){
		cin >> xo >> yo >> xi >> yi >> xii >> yii;
		int lo = min(yo, min(yi, yii));
		int hi = max(yo, max(yi, yii));
		
		segs.push_back({lo, -1});
		segs.push_back({hi, +1});
		
	}
	
	sort(segs.begin(), segs.end());
	int ans = 0, open = 0;
	for(auto &s : segs){
		open -= s.second;
		ans = max(ans, open);
	}
	
	cout << ans << endl;

	return 0;
}