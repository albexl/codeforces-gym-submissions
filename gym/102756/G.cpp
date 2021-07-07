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
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());



int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n, k;
	cin >> n >> k;

	vector<vector<int>> a(n, vector<int>(k));
	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		for(int j = 0; j < k; j++)
			a[i][j] = s[j] - '0';
	}

	vector<int> p(k);
	for(int i = 0; i < k; i++)
		p[i] = i;

	int ans = 2e9;

	do{

		vector<int> nums(n);
		int mx = -1, mn = 2e9;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < k; j++)
				nums[i] = nums[i] * 10 + a[i][p[j]];
			mx = max(mx, nums[i]);
			mn = min(mn, nums[i]);
		}

		ans = min(ans, mx - mn);

	}while(next_permutation(p.begin(), p.end()));

	cout << ans << endl;

	return 0;
}