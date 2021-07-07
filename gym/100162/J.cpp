#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef complex<double> point;
typedef pair<int, int> pii;
typedef long long ll;

const int maxn = 250 + 5;

ll dp[maxn][maxn][12];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int cases = 1;

	int n, m;
	
	while(cin >> n >> m){
		
		memset(dp, 0, sizeof(dp));
		
		vector<point> P(n);
		for(int i = 0, x, y; i < n; i++){
			cin >> x >> y;
			P[i] = point(1.0 * x, 1.0 * y);
		}
			
		vector<pair<double, pii>> p;
		
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(i != j){
					point v = P[j] - P[i];			
					p.push_back({arg(v), {i, j}});
				}
			}
		}
		
		for(int i = 0; i < n; i++)
			dp[i][i][0] = 1;
		
		sort(p.begin(), p.end());
		
		for(int i = 0; i < (int)p.size(); i++){
			int a = p[i].second.first;
			int b = p[i].second.second;
			
			//cout << P[a].real() << " " << P[a].imag() << " " << P[b].real() << " " << P[b].imag() << endl; 
			
			for(int j = 0; j < n; j++)
				for(int k = 0; k < m; k++)
					dp[j][b][k + 1] += dp[j][a][k];
		}
		
		ll ans = 0;
		for(int i = 0; i < n; i++)
			ans += dp[i][i][m];
		
		cout << "Case " << cases++ << ": " << ans << endl;
	}
	
	

	return 0;
}