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
	
	string s;
	cin >> s;
	
	int n = s.size();
	
	vector<vector<int>> dp(n + 1, vector<int>(26, -1));
	vector<int> last(26, -1);
	
	for(int i = n; i >= 0; i--){
		for(int j = 0; j < 26; j++)
			dp[i][j] = last[j];
		if(i - 1 >= 0)
			last[s[i - 1] - 'a'] = i;
	}
	
	vector<int> matched, p;
	
	matched.push_back(0);
	
	int q;
	cin >> q;
	while(q--){
		
		string op;
		cin >> op;
		
		bool ok = true;
		
		if(op == "pop"){
			p.pop_back();
			matched.pop_back();
		}
		else{
			char c;
			cin >> c;
			int pos = c - 'a';
			int last = matched.back();
			p.push_back(pos);
			if(last == -1)
				matched.push_back(-1);
			else
				matched.push_back(dp[last][pos]);
		}
		
		if(matched.back() == -1)
			ok = false;
	
		cout << (ok ? "YES" : "NO") << endl;
		
	}
	

	return 0;
}