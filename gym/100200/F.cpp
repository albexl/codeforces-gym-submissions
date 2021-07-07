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

	freopen("positive.in", "r", stdin);
	freopen("positive.out", "w", stdout);
	
	int n;
	cin >> n;
	
	vector<int> v(2 * n + 5), sum(2 * n + 5);

	for(int i = 1; i <= n; i++){
		cin >> v[i];
		v[i + n] = v[i];
	}
	
	for(int i = 1; i < 2 * n + 5; i++)
		sum[i] = sum[i - 1] + v[i];
		
	int ans = 0;
	multiset<int> s;
		
	for(int i = 1; i <= n; i++)
		s.insert(sum[i]);
	
	for(int i = 1; i <= n; i++){
		int mn = *(s.begin());
		mn -= sum[i - 1];
		
		if(mn > 0)
			ans++;
		
		s.erase(s.find(sum[i]));
		s.insert(sum[i + n]);
	}
		
	
	cout << ans << endl;	
	
	return 0;
}