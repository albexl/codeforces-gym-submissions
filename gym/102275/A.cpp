#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <random>
#include <chrono>
 
using namespace std;
using namespace __gnu_pbds;
 
#define endl '\n'
 
typedef long long ll;
typedef pair<ll, ll> pii;
typedef tree<int, null_type,less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
template<typename T>
static T randint(T lo, T hi){
	return uniform_int_distribution<T>(lo, hi)(rng);
}


 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	// freopen("dislodging_logs_input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	int t;
	cin >> t;

	for(int cases = 1; cases <= t; cases++){
		int n, m, k;
 		cin >> n >> m >> k;

		bool ok = true;

		vector<int> v;

		for(int i = 0, x, y; i < k + 1; i++){
			cin >> x >> y;
			v.push_back((x + y) % 2);
		}

		if(k == 1)
			ok = false;

		for(int i = 1; i < v.size(); i++)
			if(v[i] != v[i - 1])
				ok = false;

		cout << "Case #" << cases << ": " << (ok ? "Y" : "N") << endl;
	}

	return 0;
}