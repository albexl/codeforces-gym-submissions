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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());



int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	ll n;
	cin >> n;

	queue<ll> Q;
	Q.push(1);

	set<ll> flags;
	flags.insert(1);

	vector<ll> ans;

	while(!Q.empty()){
		ll x = Q.front();Q.pop();

		if(n % x == 0)
			ans.push_back(x);

		if((long double)x * 2 <= n && flags.find(x * 2) == flags.end()){
			Q.push(x * 2);
			flags.insert(x * 2);
		}

		if((long double)x * 5 <= n && flags.find(x * 5) == flags.end()){
			Q.push(x * 5);
			flags.insert(x * 5);
		}

	}


	sort(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for(auto &val : ans)
		cout << val << endl;

	return 0;
}