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

const ll oo = 0x3f3f3f3f3f3f3f3f;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	ll n, a, b;
	cin >> n >> a >> b;
	
	vector<ll> v(n);
	for(int i = 0; i < n; i++)
		cin >> v[i];
		
	if(a == 0){
		cout << b << endl;
		return 0;
	}
	
	
	if(a < 0){
		for(int i = 0; i < n; i++)
			v[i] = -v[i];
		ll sum = 0, opt = -oo;
		for(int i = 0; i < n; i++){
			sum += v[i];
			if(sum > opt)
				opt = sum;
			if(sum < 0)
				sum = 0;
		}
		opt = -opt;
		cout << a * opt + b << endl;
	}
	else{
		ll sum = 0, opt = -oo;
		for(int i = 0; i < n; i++){
			sum += v[i];
			if(sum > opt)
				opt = sum;
			if(sum < 0)
				sum = 0;
		}
		
		cout << a * opt + b << endl;
		
	}
	

	return 0;
}