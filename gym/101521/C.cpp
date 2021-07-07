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

struct state{
	ll lcm, divi, idx;

};

ll lcm(ll a, ll b){
	ll g = __gcd(a, b);
	return a * b / g;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	ll n, r, k;
	cin >> n >> r >> k;
	
	vector<ll> divs;
	
	for(ll i = 1; i * i <= k; i++){
		if(k % i == 0){
			if(i <= r)
				divs.push_back(i);
			if(i != k / i && k / i <= r)
				divs.push_back(k / i);
		}
	}
	
	if(n > (int)divs.size()){
		cout << -1 << endl;
		return 0;
	}
	
	int N = divs.size();
	
	vector<vector<state>> dp(N);
	set<ll> L;
	
	for(int i = 0; i < N; i++)
		dp[0].push_back({divs[i], divs[i], -1}), L.insert(divs[i]);
	
	int pos = -1;
	
	for(int i = 1; i < N; i++){
		
		if(L.find(k) != L.end()){
			pos = i - 1;
			break;
		}
		
		for(int k = 0; k < (int)dp[i - 1].size(); k++){
			for(int j = 0; j < N; j++){
				auto st = dp[i - 1][k];
				ll nlcm = lcm(st.lcm, divs[j]);
				if(L.find(nlcm) == L.end()){
					L.insert(nlcm);
					state nst = {nlcm, divs[j], k};
					dp[i].push_back(nst);
				}
			}
		}
	}
	
	if(pos == -1){
		cout << -1 << endl;
		return 0;
	}
	
	set<ll> S;
	
	int j = -1;
		
	for(int i = 0; i < (int)dp[pos].size(); i++){
		if(dp[pos][i].lcm == k){
			S.insert(dp[pos][i].divi);
			j = dp[pos][i].idx;
			pos--;
			break;
		}
	}
	
	while(pos != -1){
		
		S.insert(dp[pos][j].divi);
		j = dp[pos][j].idx;
		pos--;
	}
	
	for(int i = 0; i < (int)divs.size() && (int)S.size() < n; i++)
		if(S.find(divs[i]) == S.end())
			S.insert(divs[i]);
	
	if((int)S.size() != n){
		cout << -1 << endl;
		return 0;
	}
	
	for(auto it = S.begin(); it != S.end(); it++)
		cout << *it << " \n"[it == prev(S.end())];
	
	return 0;
}