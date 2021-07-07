#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;
//typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	freopen("jinxiety.in", "r", stdin);
	freopen("jinxiety.out", "w", stdout);
	
	int n, m;
	while(cin >> n >> m && (n + m)){
		
		vector<vector<char>> a(n + 5, vector<char>(m + 5));
		
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++)
				cin >> a[i][j];
		
		vector<vector<int>> dp(n + 5, vector<int>(m + 5)), acum(n + 5, vector<int>(m + 5));
		vector<vector<int>> left(n + 5, vector<int>(m + 5)), up(n + 5, vector<int>(m + 5));
		vector<vector<int>> right(n + 5, vector<int>(m + 5));
		
		//get leftmost pos
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				if(a[i][j] == '#'){
					if(j == 1 || a[i][j - 1] == '.')
						left[i][j] = j;
					else
						left[i][j] = left[i][j - 1];
				}
			}
		}
		
		//get rightmost pos
		for(int i = 1; i <= n; i++){
			for(int j = m; j >= 1; j--){
				if(a[i][j] == '#'){
					if(j == m || a[i][j + 1] == '.')
						right[i][j] = j;
					else
						right[i][j] = right[i][j + 1];
				}
			}
		}
		
		//get topmost pos
		for(int j = 1; j <= m; j++){
			for(int i = 1; i <= n; i++){
				if(a[i][j] == '#'){
					if(i == 1 || a[i - 1][j] == '.')
						up[i][j] = i;
					else
						up[i][j] = up[i - 1][j];
				}
			}
		}
		
		//right - down
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				int add = 0;
				if(a[i][j] == '#')
					add = 1;
				acum[i][j] = acum[i][j - 1] + acum[i - 1][j] + add - acum[i - 1][j - 1];
			}
		}
		
		int s1 = 0;
		
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				if(a[i][j] == '.') continue;
				if(acum[i - 1][j - 1] == 0)
					dp[i][j] = 0;
				else
					dp[i][j] = dp[up[i][j]][left[i][j]] + 1;
				s1 = max(s1, dp[i][j]);
			}
		}
		
		//clear
		for(int i = 0; i <= n; i++)
			for(int j = 0; j <= m; j++)
				acum[i][j] = dp[i][j] = 0;
		
		//left - down;
		for(int i = 1; i <= n; i++){
			for(int j = m; j >= 1; j--){
				int add = 0;
				if(a[i][j] == '#')
					add = 1;
				acum[i][j] = acum[i][j + 1] + acum[i - 1][j] + add - acum[i - 1][j + 1];
			}
		}
		
		int s2 = 0;
		
		for(int i = 1; i <= n; i++){
			for(int j = m; j >= 1; j--){
				if(a[i][j] == '.') continue;	
				if(acum[i - 1][j + 1] == 0)
					dp[i][j] = 0;
				else
					dp[i][j] = dp[up[i][j]][right[i][j]] + 1;
				s2 = max(s2, dp[i][j]);
			}
		}
		
		cout << max(s1, s2) << endl;
	}

	return 0;
}