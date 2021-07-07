#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <random>
#include <chrono>
 
using namespace std;
using namespace __gnu_pbds;
 
#define endl '\n'
 
typedef long long ll;
typedef pair<ll, ll> pii;
typedef tree<int, null_type,less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
template<typename T>
static T randint(T lo, T hi){
	return uniform_int_distribution<T>(lo, hi)(rng);
}


 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	//freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	
	int n, m;
	cin >> n >> m;

	vector<pii> events;
	for(int i = 0; i < m; i++){
		int l, r;
		cin >> l >> r;
		events.push_back({l, -1});
		events.push_back({r, +1});
	}

	sort(events.begin(), events.end());
	int last = 0, active = 0;

	for(auto &e : events){
		int x = e.first;
		int t = e.second;

		if(t == -1)
			active++;
		else{
			last = x;
			active--;
		}

		if(active == 1)
			if(x - last == 2){
				cout << x - 1 << endl;
				return 0;
			}
	}

	cout << n << endl;

	return 0;
}