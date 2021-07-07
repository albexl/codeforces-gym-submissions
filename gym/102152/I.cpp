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
		int n, k;
		cin >> n >> k;
		
		multiset<int> s;
		
		for(int i = 0, x; i < n; i++){
			cin >> x;
			s.insert(x);
		}
		
		while(k--){
			int x = *(s.begin());
			s.erase(s.find(x));
			s.insert(-x);
		}
		
		int sum = 0;
		for(auto &v : s)
			sum += v;
		
		cout << sum << endl;
		
	}

	return 0;
}