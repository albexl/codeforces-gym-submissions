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
	
	int n, k;
	cin >> n >> k;
	
	vector<int> v(n);
	for(int i = 0; i < n; i++)
		cin >> v[i];
	
	int lo = 0, hi = n, ans = -1;
	while(lo <= hi){
		int mid = (lo + hi) >> 1;
		
		int cnt = 0, convinced = 0;
		
		for(int i = 0; i < n; i++){
			if(v[i] <= cnt)
				cnt++;
			else{
				if(convinced < mid){
					convinced++;
					cnt++;
				}
			}
		}
			
		
		if(cnt >= k){
			ans = mid;
			hi = mid - 1;
		}
		else lo = mid + 1;
	}

	cout << ans << endl;

	return 0;
}