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



int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	// freopen("settling.in", "r", stdin);
	// freopen("settling.out", "w", stdout);

	int n;
	cin >> n;

	multiset<ll> s;
	for(int i = 0; i < n; i++){
		ll x;
		cin >> x;
		s.insert(x);
	}

	while(s.size() > 1){
		ll mx = *(s.rbegin());
		ll mn = *(s.begin());

		if(mn == mx){
			cout << "NO" << endl;
			return 0;
		}

		s.erase(s.find(mn));
		s.erase(s.find(mx));
		s.insert(mx + 1);
	}

	cout << "YES" << endl;

	return 0;
}