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
	
	string ans = "";
	
	ans += s[0];
	
	for(int i = 0; i + 1 < n; i++){
		
		int p = (s[i + 1] + 26 - s[i]) % 26;
		ans += (char)(p + 'a');
		
	}

	cout << ans << endl;

	return 0;
}