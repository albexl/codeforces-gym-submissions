#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long ll;

const int maxn = 40;
ll dp[maxn][maxn];
char a[maxn][maxn];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			cin >> a[i][j];
	
	for(int i = 1; i <= m; i++){
		int low = 1;
		
		if(i != 1)
			low--;
			
		for(int j = low; j <= n; j++){
			bool ok1 = true, ok2 = true;
			
			for(int k = j + 1; k <= n; k++)
				if(a[k][i] == 'B')
					ok1 = false;
			
			for(int k = j; k >= 1; k--)
				if(a[k][i] == 'R')
					ok2 = false;
			
			if(ok1 && ok2){
				if(i != 1){
					for(int k = j; k <= n; k++)
						dp[i][j] += dp[i - 1][k];
				}
				else
					dp[i][j] = 1;
			}
		}
	}
	
	ll ans = 0;
	for(int i = 0; i <= n; i++)
		ans += dp[m][i];
	
	cout << ans << endl;

	return 0;
}