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
	
	int tc;
	cin >> tc;
	
	for(int cases = 1; cases <= tc; cases++){
		int g, p;
		cin >> g >> p;
		
		cout << "Team #" << cases << endl;
		cout << "Games: " << g << endl;
		cout << "Points: " << p << endl;
		cout << "Possible records:" << endl;
		
		
		for(int k = g; k >= 0; k--){
			int w = k * 3;
			if(w > p)
				continue;
			
			int rem = p - w;
			
			if(rem + k > g)
				continue;
			
			
			cout << k << "-" << rem << "-" << g - k - rem << endl; 
			
		}
		
		cout << endl;
		
	}
	

	return 0;
}