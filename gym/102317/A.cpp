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
	
	int t;
	cin >> t;
	
	while(t--){
		
		vector<int> v(3);
		cin >> v[0] >> v[1] >> v[2];
		
		int cnt = 0;
		cnt += (v[0] >= 10);
		cnt += (v[1] >= 10);
		cnt += (v[2] >= 10);
		
		cout << v[0] << " " << v[1] << " " << v[2] << endl;
		if(cnt == 0)
			cout << "zilch" << endl;
		if(cnt == 1)
			cout << "double" << endl;
		if(cnt == 2)
			cout << "double-double" << endl;
		if(cnt == 3)
			cout << "triple-double" << endl;
		cout << endl;
		
	}

	return 0;
}