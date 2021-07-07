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

const int maxn = 150;

int dp[maxn][6][6][33];
vector<string> movies[maxn][6];
vector<string> seen;

int get(int x){
	return x - 1870;
}


int solve(int pos, int region, int swaps, int mask){
	if(pos == 2005 - 1870)
		return 0;
	
	if(dp[pos][region][swaps][mask] != -1)
		return dp[pos][region][swaps][mask];
	
	int ans = 0, add = 0;
	
	if(!( mask & (1 << region) ))
		add = movies[pos][region].size();
	
	ans = max(ans, add + solve(pos + 1, region, swaps, 0));
	
	for(int i = 0; i < 5; i++)
		if(i != region && swaps > 0)
			ans = max(ans, add + solve(pos, i, swaps - 1, mask | (1 << region) ) );
	
	return dp[pos][region][swaps][mask] = ans;
}

void gen(int pos, int region, int swaps, int mask){
	if(pos == 2005 - 1870)
		return;
	
	int ans = 0, add = 0, opt = -1;
	
	if(!( mask & (1 << region) )){
		for(auto &el : movies[pos][region])
			seen.push_back(el);	
	}
	
	ans = add + dp[pos + 1][region][swaps][0];
	
	for(int i = 0; i < 5; i++){
		if(i != region && swaps > 0){
			int mx = add + dp[pos][i][swaps - 1][mask | (1 << region)];
			if(mx > ans){
				ans = mx;
				opt = i;
			}
		}
	}
	
	if(opt == -1)
		gen(pos + 1, region, swaps, 0);
	else
		gen(pos, opt, swaps - 1, mask | (1 << region));
	
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	freopen("dvd.in", "r", stdin);
	freopen("dvd.out", "w", stdout);
	
	memset(dp, -1, sizeof(dp));
	
	int n;
	cin >> n;
	
	for(int i = 0; i < n; i++){
		string cur = "";
		string s;
		
		while(cin >> s){
			cur += s;
			if(s.back() != '"')
				cur += " ";
			else
				break;
		}
		
		int year, region;
		cin >> year >> region;
		year = get(year);
		
		movies[year][region - 1].push_back(cur);
	}
	
	int ans = 0, opt = -1;
	
	for(int i = 0; i < 5; i++){
		int mx = max(ans, solve(0, i, 5, 0));
		if(mx > ans){
			ans = mx;
			opt = i;
		}
	}
	
	gen(0, opt, 5, 0);
	
	cout << ans << endl;
	for(auto &el : seen)
		cout << el << endl;

	return 0;
}