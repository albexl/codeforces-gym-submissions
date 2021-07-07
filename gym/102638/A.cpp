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
 
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	
	cout << 228 << endl;
	return 0;

	for(ll x = 3; x <= 1000; x++){

		ll s1 = x - 3;

		double x1 = sqrt(s1);
		ll X1 = sqrt(s1);

		if(x1 != X1)
			continue;

		ll s2 = 3 * x + 2;
		if(s2 % 2)
			continue;

		s2 /= 2;
		double x2 = cbrt(s2);
		ll X2 = cbrt(s2);

		if(x2 != X2)
			continue;

		ll num = X1 - X2, left = 1;
		for(int i = 0; i < 7; i++)
			left *= num;


		ll X3 = x;

		ll s4 = x * x - 1984;
		if(s4 % 5)
			continue;

		s4 /= 5;
		double x4 = sqrt(s4);
		ll X4 = sqrt(s4);

		if(x4 != X4)
			continue;

		num = X3 - X4;
		ll right = 1;
		for(int i = 0; i < 3; i++)
			right *= num;

		if(left == right){
			cout << x << endl;
		}

	}



	return 0;
}