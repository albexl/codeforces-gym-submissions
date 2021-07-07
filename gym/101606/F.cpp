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

const int maxn = 400 + 5;

double dp[maxn][maxn];
bool ok[maxn][maxn];

int n, k;

double solve(int pos, int heads){
	
	//cout << pos << " " << heads << " " << k << endl;
	
	if(pos == k)
		return 1.0 * heads;
		
	if(ok[pos][heads])
		return dp[pos][heads];
	ok[pos][heads] = true;
	
	double s1 = 0.5 * solve(pos + 1, heads), s2 = 0;
	if(heads == n)
		s2 = 0.5 * solve(pos + 1, heads - 1);
	else
		s2 = 0.5 * solve(pos + 1, heads + 1);
	
	
	//cout << s1 << " " << s2 << endl;
	
	return dp[pos][heads] = s1 + s2;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	cout << setprecision(10) << fixed;
	
	cin >> n >> k;
	
	cout << solve(0, 0) << endl;

	return 0;
}