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
	
	const ll mod = 1e9 + 7;
	
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		
		int n = s.size();
		
		vector<vector<ll>> dp(n, vector<ll>(n));
		for(int i = 0; i < n; i++)
			dp[i][i] = 1;
		
		for(int i = 0; i + 1 < n; i++)
			dp[i][i + 1] = 1 + (s[i] == s[i + 1]);
		
		for(int sz = 3; sz <= n; sz++){
			for(int i = 0; i + sz <= n; i++){
				int lo = i, hi = i + sz - 1;
				
				dp[lo][hi] = 1;
				
				int sum = 0;
				for(int k = lo; k <= hi; k++)
					sum += s[k] - '0';
				
				int s1 = 0;
				
				for(int k = lo; k < hi; k++){
					s1 += s[k] - '0';
					
					int s2 = sum - s1;
					
					if(s1 == s2)
						dp[lo][hi]++;
				}
				
				s1 = 0;
				for(int k = lo; k <= hi; k++){
					s1 += s[k] - '0';
					int s2 = 0;
					for(int l = hi; k + 2 <= l; l--){
						s2 += s[l] - '0';
						if(s1 == s2)
							dp[lo][hi] += dp[k + 1][l - 1], dp[lo][hi] %= mod;
					}
				}
				
			}
		}
		
		cout << dp[0][n - 1] << endl;
	}
	

	return 0;
}