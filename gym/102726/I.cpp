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
typedef tree<int, null_type,less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
template<typename T>
static T randint(T lo, T hi){
	return uniform_int_distribution<T>(lo, hi)(rng);
}

const ll mod = 1e9 + 7;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	// freopen("settling.in", "r", stdin);
	// freopen("settling.out", "w", stdout);


	int n;
	cin >> n;

	vector<ll> a(n + 1);
	for(int i = 1; i <= n; i++)
		cin >> a[i];

	vector<vector<ll>> dp(n + 1, vector<ll>(n + 1));
	for(int i = 1; i + 1 <= n; i++)
		dp[i][i + 1] = a[i] ^ a[i + 1];

	for(int sz = 3; sz <= n; sz++){
		for(int i = 1; i + sz - 1 <= n; i++){
			int lo = i, hi = i + sz - 1;
			dp[lo][hi] = (dp[lo + 1][hi] + dp[lo][hi - 1]) % mod;
		}
	}
	
	
	cout << dp[1][n] << endl;
	
	return 0;
}