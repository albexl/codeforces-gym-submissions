#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <random>
#include <chrono>
 
using namespace std;
using namespace __gnu_pbds;
 
#define endl '\n'
 
typedef long long ll;
typedef pair<ll, ll> pii;
typedef tree<int, null_type,less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
template<typename T>
static T randint(T lo, T hi){
	return uniform_int_distribution<T>(lo, hi)(rng);
}



int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	// freopen("settling.in", "r", stdin);
	// freopen("settling.out", "w", stdout);

	string s;
	cin >> s;

	int n = s.size();

	vector<vector<int>> nxt(n + 5, vector<int>(26, -1));

	for(int i = n - 1; i >= 0; i--){
		nxt[i] = nxt[i + 1];
		nxt[i][s[i] - 'a'] = i;
	}

	int q;
	cin >> q;

	while(q--){
		string x;
		cin >> x;

		string ans = "";
		int m = x.size();

		for(int i = 0, pos = 0; i < m; i++){
			if(nxt[pos][x[i] - 'a'] == -1)
				break;
			ans += x[i];
			pos = nxt[pos][x[i] - 'a'] + 1;
		}

		if(ans == "")
			ans = "IMPOSSIBLE";

		cout << ans << endl;
	}

	return 0;
}