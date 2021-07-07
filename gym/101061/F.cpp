#include<bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

#define endl '\n'
#define MAX

typedef long long ll;
typedef pair<int,int> pii;
//typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;

const int maxn = 100 + 5;
const int maxm = 20000 + 5;

int dp[maxn][maxm];
int a[maxn], n;

int solve(int pos, int diff){
	if(pos == n)
		return abs(diff);
	if(dp[pos][diff + 10000] != -1)
		return dp[pos][diff + 10000];
	
	int s1 = max(abs(diff), solve(pos + 1, diff + a[pos]));
	int s2 = max(abs(diff), solve(pos + 1, diff - a[pos]));
	
	return dp[pos][diff + 10000] = min(s1, s2);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		for(int i = 0; i < n; i++)
			cin >> a[i];
		memset(dp, -1, sizeof(dp));
		cout << solve(0, 0) << endl;
	}

	return 0;
}