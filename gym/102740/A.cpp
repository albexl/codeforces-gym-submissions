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
typedef tree<int, null_type,less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
template<typename T>
static T randint(T lo, T hi){
	return uniform_int_distribution<T>(lo, hi)(rng);
}


int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	// freopen("settling.in", "r", stdin);
	// freopen("settling.out", "w", stdout);

	vector<ll> v(3);
	cin >> v[0] >> v[1] >> v[2];

	int q;
	cin >> q;

	while(q--){
		vector<ll> a(3), b(3);
		ll s1 = 0, s2 = 0;
		for(int i = 0; i < 3; i++){
			cin >> a[i];
			s1 += a[i] * v[i];
		}

		for(int i = 0; i < 3; i++){
			cin >> b[i];
			s2 += b[i] * v[i];
		}

		if(s1 > s2)
			cout << "Jett" << endl;
		else if(s1 < s2)
			cout << "Breach" << endl;
		else
			cout << "Tie" << endl;
	}

	return 0;
}