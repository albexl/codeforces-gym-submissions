#include<bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

#define endl '\n'
#define MAX

typedef long long ll;
typedef pair<int,int> pii;
//typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	int t;
	cin >> t;
	while(t--){
		int n, m, k;
		cin >> n >> m >> k;
		string a, b;
		cin >> a >> b;
		
		vector<set<char>> M(26);
		
		for(int i = 0; i + k - 1 <= n - 1; i++){
			char c1 = a[i];
			char c2 = a[i + k - 1];
			M[c2 - 'a'].insert(c1);
		}
		
		ll ans = 0;
		map<char, ll> dp;
		
		for(int i = 0; i < m; i++){
			dp[b[i]]++;
			for(auto &c : M[b[i] - 'a'])
				ans += dp[c];
		}
		
		
		cout << ans << endl;
	}

	return 0;
}