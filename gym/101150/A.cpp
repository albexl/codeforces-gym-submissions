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
	
	const int maxn = 10000 + 5;
	
	vector<int> primes;
	vector<int> dp(maxn);
	vector<bool> seen(maxn, false);
	
	for(int i = 2; i < maxn; i++){
		if(!seen[i]){
			primes.push_back(i);
			for(int j = i + i; j < maxn; j += i)
				seen[j] = true;
		}
	}
	
	for(int i = 0; i < primes.size(); i++){
		int s = 0;
		for(int j = i; j < primes.size(); j++){
			s += primes[j];
			if(s < maxn)
				dp[s]++;
			else
				break;
		}
	}
	
	int x;
	while(cin >> x && x){
		cout << dp[x] << endl;
	}	

	return 0;
}