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
// typedef tree<int, null_type,less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
// template<typename T>
// static T randint(T lo, T hi){
// 	return uniform_int_distribution<T>(lo, hi)(rng);
// }

vector<ll> decomp(ll x, ll b){
	vector<ll> rems;

	while(x > 0){
		rems.push_back(x % b);
		x /= b;
	}

	return rems;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	// freopen("settling.in", "r", stdin);
	// freopen("settling.out", "w", stdout);

	ll n, k, x;
	cin >> n >> k >> x;

	auto dec = decomp(n, x);

	ll cnt = 0;
	priority_queue<ll> pq;
	for(ll i = 0; i < dec.size(); i++){
		cnt += dec[i];
		for(int j = 0; j < dec[i]; j++)
			pq.push(i);
	}

	if(cnt > k){
		cout << "NO" << endl;
		return 0;
	}

	while(cnt < k && pq.top() > 0){
		ll v = pq.top();pq.pop();
		cnt += x - 1;
		for(int j = 0; j < x; j++)
			pq.push(v - 1);
	}

	if(cnt != k){
		cout << "NO" << endl;
		return 0;
	}

	vector<ll> ans;
	while(!pq.empty()){
		ll x = pq.top();pq.pop();
		ans.push_back(x);
	}

	cout << "YES" << endl;
	for(int i = 0; i < ans.size(); i++){
		ll val = 1;
		for(int j = 0; j < ans[i]; j++)
			val *= x;
		cout << val << " \n"[i + 1 == ans.size()];
	}

	return 0;
}