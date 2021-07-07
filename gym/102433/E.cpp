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

const ll mod = 11092019;
const int maxn = 1e5 + 5;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	//mt19937 rng(5);
	//srand(time(0));

	string s;
	cin >> s;
	
	int n = s.size();
	
	vector<ll> dp(n + 1);
	vector<ll> cnt(26);
	
	dp[0] = 1ll;
	for(int i = 1; i <= n; i++){
		dp[i] = dp[i - 1];
		
		int p = s[i - 1] - 'a';
		
		ll cur = 1ll;
		for(int j = 0; j < 26; j++)
			if(j != p)
				cur = (cur * (cnt[j] + 1)) % mod;
		
		dp[i] = (dp[i] + cur) % mod;
		cnt[p]++;
	}
	
	cout << dp[n] << endl;

	return 0;
}