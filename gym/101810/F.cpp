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
	
	const int maxn = 1e6 + 5;
	
	vector<int> f(maxn);
	
	int t;
	cin >> t;
	
	while(t--){
		
		int n;
		cin >> n;
		
		vector<int> v(n);
		
		for(int i = 0; i < n; i++){
			cin >> v[i];
			f[v[i]]++;
		}
		
		ll ans = 0;
		
		for(int i = 1; i < maxn; i++){
			if(f[i]){
				for(int j = i + i; j < maxn; j += i){
					f[i] += f[j];
					f[j] = 0;
				}
				
				ans += 1ll * i * f[i];
			}
		}
		
		cout << ans << endl;
		
		for(int i = 0; i < n; i++)
			f[v[i]] = 0;
		
	}

	return 0;
}