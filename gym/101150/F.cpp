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

	cout << setprecision(10) << fixed;
	
	const double oo = 1e15;
	const int maxn = 1e4 + 5;
	
	int n;
	while(cin >> n && n){
		
		vector<int> a(n + 1);
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		
		double b;
		cin >> b;
		
		int r;
		double v, e, f;
		cin >> r >> v >> e >> f;
		
		
		vector<double> acum1(maxn), acum2(maxn);
		
		for(int i = 0; i < maxn; i++){
			acum1[i] = 1.0 / (v - e * i);
			if(i){
				acum1[i] += acum1[i - 1];
				acum2[i] = 1.0 / (v - f * i);
				acum2[i] += acum2[i - 1];
			}
		}
		
		
		vector<double> dp(n + 1, oo);
		dp[0] = 0;
		
		for(int i = 1; i <= n; i++){
			
			for(int j = 0; j < i; j++){
				int x = a[i] - a[j] - 1;
				double cost = 0.0;
				
				if(x >= r)
					cost += acum1[x - r], cost += acum2[r];
				else
					cost += acum2[r] - acum2[r - x - 1];
				
				if(j)
					cost += b;
				dp[i] = min(dp[i], dp[j] + cost);
			}
		}
		
		cout << dp[n] << endl;
		
	}

	return 0;
}