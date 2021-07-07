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
	
	int cases = 1;
	
	while(t--){
		int n, m;
		cin >> n >> m;
		
		set<string> S;
		
		for(int i = 0; i < n; i++){
			string s;
			cin >> s;
			if(s.size() > 2)
				sort(s.begin() + 1, s.end() - 1);
			S.insert(s);
		}
		
		string ans = "";
		while(m--){
			string s;
			cin >> s;
			if(s.size() > 2)
				sort(s.begin() + 1, s.end() - 1);
			if(S.count(s))
				ans += "1";
			else
				ans += "0";
		}
		
		cout << "Case #" << cases++ << ": " << ans << endl; 
	}

	return 0;
}