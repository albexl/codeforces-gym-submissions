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
	
	int t;
	cin >> t;
	while(t--){
		
		int n, m;
		cin >> n >> m;
		
		vector<int> h(2 * n);
		
		vector<int> a(m + 5), x(m + 5);
		
		for(int i = 0; i < m; i++)
			cin >> a[i];
			
		for(int i = 0; i < m; i++)
			cin >> x[i];

		for(int i = 0; i < m; i++){
			if(x[i] == 0)
				h[a[i]]++, h[a[i] + 1]--;
			else if(x[i] < 0){
				if(a[i] - x[i] >= 1){
					h[a[i] + 1]--;
					h[a[i] - x[i]]++;
				}
				else{
					h[1]++;
					h[a[i] + 1]--;
					h[n + 1]--;
					int left = x[i] - a[i] + 1;
					h[n - left + 1]++;
				}
			}
			else{
				if(a[i] + x[i] <= n){
					h[a[i]]++;
					h[a[i] + x[i] + 1]--;
				}
				else{
					h[a[i]]++;
					h[n + 1]--;
					h[1]++;
					int left = x[i] - (n - a[i]);
					h[left + 1]--;
				}
			}
		}
		
		int opt = -1, best = -1;
		
		for(int i = 1; i <= n; i++)
			h[i] += h[i - 1];

		for(int i = 1; i <= n; i++)
			if(h[i] > best)
				best = h[i], opt = i;

		cout << opt << " " << best << endl;
	}

	return 0;
}