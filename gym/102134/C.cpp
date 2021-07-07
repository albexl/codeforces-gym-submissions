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

const int maxn = 1000 + 5;
bool dp[maxn][maxn], seen[maxn][maxn];
string s;
int n, k;

bool solve(int pos, int rem){
	if(pos == n)
		return dp[pos][rem] = (rem == 0);
	if(seen[pos][rem])
		return dp[pos][rem];
	seen[pos][rem] = true;
	bool ans = false;
	if(s[pos] == '?'){
		int start = 0;
		if(pos == 0)
			start++;
		if(n == 1)
			start = 0;
		for(int i = start; i < 10; i++)
			ans |= solve(pos + 1, ((rem * 10) % k + i) % k);
	}
	else{
		int x = s[pos] - '0';
		ans |= solve(pos + 1, ((rem * 10) % k + x) % k);
	}
	return dp[pos][rem] = ans;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	cin >> n >> k >> s;
	
	bool ans = solve(0, 0);
	if(!ans)
		cout << -1 << endl;
	else{
		//cout << "cool" << endl;
	
		string num = "";
		int p = 0, r = 0;
		while(p < n){
			if(s[p] != '?'){
				num += s[p];
				int x = s[p] - '0';
				r = ((r * 10) % k + x) % k;
			}
			else{
				int start = 0;
				if(p == 0)
					start++;
				if(n == 1)
					start = 0;
				for(int i = start; i < 10; i++){
					int rr = ((r * 10) % k + i) % k;
					if(dp[p + 1][rr]){
						num += (char)(i + '0');
						r = rr;
						break;
					}
				}
			}
			p++;
		}
		
		if(n > 1 && num[0] == '0')
			cout << -1 << endl;
		else
			cout << num << endl;
	}

	return 0;
}