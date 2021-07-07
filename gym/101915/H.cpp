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
	
	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		vector<ll> a;
		for(int i = 0; i < n; i++){
			vector<ll> b(3);
			for(int j = 0; j < 3; j++)
				cin >> b[j];
			sort(b.begin(), b.end());
			a.push_back(b[0]);
			a.push_back(b[1]);
		}
		sort(a.begin(), a.end());
		ll ans = 0;
		for(int i = 0; i < k; i++)
			ans += a[i];
		cout << ans << endl;
	}

	return 0;
}