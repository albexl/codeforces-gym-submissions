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

const int maxn = 1e7 + 5;

ll f[maxn];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	int t;
	cin >> t;
	
	for(int cases = 1; cases <= t; cases++){
		cout << "Test case #" << cases << ": ";
		
		ll ans = 0;
		
		int n;
		cin >> n;
		
		vector<int> v(n);
		int mx = 0;
		for(int i = 0; i < n; i++){
			cin >> v[i];
			f[v[i]]++;
			mx = max(mx, v[i]);
		}
		
		ans += 1ll * f[0] * (n - f[0]);
		ans += 1ll * f[1] * (n - f[0] - f[1]);
		
		for(int i = 2; i <= mx / 2; i++){
			if(f[i]){
				for(int j = i + i; j <= mx; j += i)
					ans += f[i] * f[j];
			}
		}
		
		for(int i = 0; i < n; i++)
			f[v[i]]--;
		
		cout << ans << endl << endl;
		
	}

	return 0;
}