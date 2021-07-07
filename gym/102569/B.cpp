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

int solve(vector<ll> x, vector<ll> y, ll w){
	int ans = 0;
	
	for(int i = 0; i < x.size(); i++){
		ll cnt = x[i];
		if(w >= cnt)
			ans = max(ans, i + 1);
		cnt *= 2;
		
		int lo = 0, hi = (int)y.size() - 1, opt = -1;
		while(lo <= hi){
			int mid = (lo + hi) >> 1;
			if(y[mid] + cnt <= w){
				opt = mid;
				lo = mid + 1;
			}
			else hi = mid - 1;
		}
		
		if(opt != -1)
			ans = max(ans, i + 1 + opt + 1);
	}
	
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	int n;
	ll x;
	cin >> n >> x;
	
	vector<ll> pos, neg;
	
	for(int i = 0; i < n; i++){
		ll w;
		cin >> w;
		
		if(w > 0)
			pos.push_back(w);
		else
			neg.push_back(-w);
	}
	
	sort(pos.begin(), pos.end());
	sort(neg.begin(), neg.end());
	
	int ans = 0;
	ans = max(ans, solve(pos, neg, x));
	ans = max(ans, solve(neg, pos, x));
	
	cout << ans << endl;

	return 0;
}