#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 10000 + 2;

int cnt[52], n;
double dp[maxn][52][52], p[52];
bool seen[maxn][52][52];

double f(int att, int pos, int have){
	if(pos == n)
		return 1.0;
	if(have == cnt[pos])
		return f(att, pos + 1, 0);
	if(att <= 0)
		return 0.0;
	if(seen[att][pos][have])
		return dp[att][pos][have];
	seen[att][pos][have] = true;
	
	double ans = 0.0;
	ans += p[pos] * f(att - 1, pos, have + 1);
	ans += (1.0 - p[pos]) * f(att - 1, pos, have);
	
	return dp[att][pos][have] = ans;
}

double solve(){
	
	
	cin >> n;
	
	for(int i = 0; i < n; i++)
		cin >> cnt[i] >> p[i];
	
	int att;
	cin >> att;
	
	for(int i = 0; i <= att; i++)
		for(int j = 0; j < n; j++)
			for(int k = 0; k <= cnt[j]; k++)
				seen[i][j][k] = false;
	
	return f(att, 0, 0);
}


int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cout << setprecision(3) << fixed;
	

	int t;
	cin >> t;
	
	while(t--){
		cout << solve() << endl;
	}


	return 0;
}

/*

4
2
3 0.5
3 0.3
20
4
2 0.75
1 0.01
2 1.0
3 0.8
25

2
1 0.5
1 0.3
2
2
50 .4
50 .3
250

*/