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
	
	const ll oo = 99999999;
	
	int n;
	cin >> n;
	
	vector<ll> v(n);
	
	for(int i = 0; i < n; i++)
		cin >> v[i];
	
	sort(v.begin(), v.end());
	
	do{
		
		bool ok = true;
		ll sum = 0;
		
		for(int i = 0; i < n; i++){
			sum += v[i];
			if(sum < 0 || sum > oo)
				ok = false;
		}
		
		if(ok){
			for(int i = 0; i < n; i++)
				cout << v[i] << endl;
			return 0;
		}
		
	}while(next_permutation(v.begin(), v.end()));
	
	
	
	cout << "Error" << endl;

	return 0;
}