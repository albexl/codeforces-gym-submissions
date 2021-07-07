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

vector<int> prefix_function(const string &p)
{
	int n = p.length();

	vector<int> pref(n + 1);

	for (int i = 0, j = pref[0] = -1; i < n; pref[++i] = ++j)
		while (j >= 0 && p[i] != p[j]) j = pref[j];

	return pref;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	freopen("decomp.in", "r", stdin);
	freopen("decomp.out", "w", stdout);

	string s;
	cin >> s;
	
	int n = (int)s.size();
	
	vector<vector<int>> v;
	
	for(int i = 0; i < n; ++i){
		string x = "";
		for(int j = i; j < n; j++)
			x += s[j];
		auto p = prefix_function(x);
		v.push_back(p);
	}
	
	//for(int i = 0; i < (int)v.size(); i++)
	//	for(int j = 0; j < (int)v[i].size(); j++)
	//		cout << v[i][j] << " \n"[j + 1 == (int)v[i].size()];

	const int oo = 1e9;

	vector<int> dp(n + 1, oo), opt(n + 1, -1), C(n + 1), D(n + 1);
	dp[0] = 0;
	
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < i; j++){
			int x = dp[j], cost = 0;
			int sz = i - j;
			int pref = v[j][sz];
			pref = sz - pref;
			if(sz % pref == 0)
				cost = pref;
			else
				cost = sz;
			if(x + cost < dp[i])
				dp[i] = x + cost, opt[i] = j, C[i] = cost, D[i] = sz / cost;
		}
	}
	
	cout << dp[n] << endl;
	vector<pair<string, int>> ans;
	
	int pos = n;
	while(pos != 0){
		//cout << pos << " " << C[pos] << " " << D[pos] << endl;
		int l = C[pos], r = D[pos];
		int aux = l;
		pos = opt[pos];
		string x = "";
		for(int j = pos; aux > 0; j++, aux--)
			x += s[j];
		ans.push_back({x, r});
	}
	
	reverse(ans.begin(), ans.end());
	for(int i = 0; i < ans.size(); i++)
		cout << ans[i].first << " " << ans[i].second << endl;

	return 0;
}