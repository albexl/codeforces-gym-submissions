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

bool ok(string s, int d){
	int rem = 0;
	for(auto &c : s){
		rem = rem * 10 + (c - '0');
		rem %= d;
	}
	return rem == 0;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		
		vector<string> ans;
		
		if(ok(s, 3))
			ans.push_back("AGENT 003");
		if(ok(s, 5))
			ans.push_back("AGENT 005");
		if(ok(s, 7))
			ans.push_back("AGENT 007");
		
		if(ans.empty())
			cout << "NONE" << endl;
		else{
			for(auto &el : ans)
				cout << el << endl;
		}
		cout << "---" << endl;
	}

	return 0;
}