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


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	//mt19937 rng(5);
	//srand(time(0));
	
	while(true){
		int n, m;
		cin >> n >> m;
		
		if(n == 0)
			break;
		
		vector<string> a(n);
		vector<string> ans(n, string(m, '.'));
		for(int i = 0; i < n; i++)
			cin >> a[i];
		
		
		vector<int> dx = {1, -1, 0, 0, 1, 1, -1, -1};
		vector<int> dy = {0, 0, 1, -1, 1, -1, 1, -1};
		
		
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(a[i][j] == '*')
					ans[i][j] = a[i][j];
				else{
					int cnt = 0;
					
					for(int k = 0; k < 8; k++){
						int ii = i + dx[k];
						int jj = j + dy[k];
						
						if(ii >= 0 && ii < n && jj >= 0 && jj < m && a[ii][jj] == '*')
							++cnt;
					}
					
					ans[i][j] = (char)(cnt + '0');
				}
			}
		}
		
		for(int i = 0; i < n; i++)
			cout << ans[i] << endl;
	}
	
	
	

	return 0;
}