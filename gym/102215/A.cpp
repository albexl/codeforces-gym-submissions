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
	
	int n;
	cin >> n;
	
	vector<int> v(n);
	for(int i = 0; i < n; i++)
		cin >> v[i];
	
	vector<int> last(n + 1, n), ans(n);
	multiset<int> keys, pos;
	for(int i = n - 1; i >= 0; i--){
		
		
		if(v[i] > 0){
			
			if(pos.size() == 0)
				ans[i] = n - i;
			else{
				int low = *pos.begin();
				ans[i] = low - i;
			}
			
			last[v[i]] = i;
			
		}
		else{
			
			pos.insert(last[-v[i]]);
		
			
			if(pos.size() == 0)
				ans[i] = n - i;
			else{
				int low = *pos.begin();
				ans[i] = low - i;
			}
		}
		
	}
	
	for(int i = 0; i < n; i++)
		cout << ans[i] << " \n"[i + 1 == n];

	return 0;
}