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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n;
	cin >> n;

	vector<int> dp(n + 1);

	int ans = 0;

	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		dp[x] = dp[x - 1] + 1;
		ans = max(ans, dp[x]);
	}

	cout << n - ans << endl;

	return 0;
}