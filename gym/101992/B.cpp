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
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	freopen("task.in", "r", stdin);
	//freopen("output.txt", "w", stdout);


	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;

		vector<int> v(n);
		for(int i = 0; i < n; i++)
			cin >> v[i];

		int ans = n + 1;
		sort(v.begin(), v.end());
		v.resize(unique(v.begin(), v.end()) - v.begin());

		int add = n - v.size();

		n = v.size();

		for(int i = 1; i <= 5 * n + 5; i++){
			int pos = upper_bound(v.begin(), v.end(), i) - v.begin();
			ans = min(ans, i - pos + n - pos + add);
		}

		cout << ans << endl;
	}


	return 0;
			
}