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

	
	int t;
	cin >> t;

	while(t--){
		
		int n;
		cin >> n;

		if(n == 1)
			cout << "Neither" << endl;
		else{
			bool ok = true;
			for(int i = 2; i * i <= n; i++)
				if(n % i == 0)
					ok = false;

			cout << (ok ? "Prime" : "Composite") << endl;
		}

	}

	return 0;
}