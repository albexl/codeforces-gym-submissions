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

bool ok(char c){
	return c == 'A' || c == 'I' || c == 'H' || c == 'M' || c == 'O' || c == 'T' || c == 'U' || c == 'V' || c == 'W' || c == 'X' || c == 'Y';
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
		
		int n = s.size();
		
		vector<vector<bool>> pal(n, vector<bool>(n, false));
		
		int ans = 0;
		
		for(int i = 0; i < n; i++)
			if(ok(s[i]))
				pal[i][i] = true, ans = 1;
		
		for(int i = 0; i + 1 < n; i++)
			if(ok(s[i]) && ok(s[i + 1]) && s[i] == s[i + 1])
				pal[i][i + 1] = true, ans = 2;
		
		for(int sz = 3; sz <= n; sz++)
			for(int i = 0; i + sz - 1 < n; i++){
				int lo = i, hi = i + sz - 1;
				pal[lo][hi] = (pal[lo + 1][hi - 1] && ok(s[lo]) && ok(s[hi]) && s[lo] == s[hi]);
				if(pal[lo][hi])
					ans = sz;
			}
		
		cout << ans << endl;
		
	}

	return 0;
}