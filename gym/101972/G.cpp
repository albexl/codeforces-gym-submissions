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

const int maxn = 555;

ll a[maxn][maxn];

ll RU[maxn][maxn], LU[maxn][maxn], RD[maxn][maxn], LD[maxn][maxn];

const ll oo = 1e12;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
		
		memset(RU, 0, sizeof(RU));
		memset(LU, 0, sizeof(LU));
		memset(RD, 0, sizeof(RD));
		memset(LD, 0, sizeof(LD));
		
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++){
				cin >> a[i][j];
				RU[i][j] = LU[i][j] = RD[i][j] = LD[i][j] = a[i][j];
			}
		
		for(int i = 1; i <= n ; i++)
			for(int j = 1; j <= m; j++){
				LU[i][j] = max(LU[i][j], LU[i][j - 1]);
				LU[i][j] = max(LU[i][j], LU[i - 1][j - 1]);
				LU[i][j] = max(LU[i][j], LU[i - 1][j]);
			}

		for(int i = 1; i <= n; i++)
			for(int j = m; j >= 1; j--){
				RU[i][j] = max(RU[i][j], RU[i][j + 1]);
				RU[i][j] = max(RU[i][j], RU[i - 1][j + 1]);
				RU[i][j] = max(RU[i][j], RU[i - 1][j]);
			}
		
		for(int i = n; i >= 1; i--)
			for(int j = 1; j <= m; j++){
				LD[i][j] = max(LD[i][j], LD[i + 1][j]);
				LD[i][j] = max(LD[i][j], LD[i + 1][j - 1]);
				LD[i][j] = max(LD[i][j], LD[i][j - 1]);
			}

		for(int i = n; i >= 1; i--)
			for(int j = m; j >= 1; j--){
				RD[i][j] = max(RD[i][j], RD[i + 1][j]);
				RD[i][j] = max(RD[i][j], RD[i + 1][j + 1]);
				RD[i][j] = max(RD[i][j], RD[i][j + 1]);
			}
		
		ll ans = oo;
		
		for(int i = 2; i < n; i++){
			for(int j = 2; j < m; j++){
				vector<ll> b;
				b.push_back(LU[i - 1][j - 1]);
				b.push_back(LD[i + 1][j - 1]);
				b.push_back(RU[i - 1][j + 1]);
				b.push_back(RD[i + 1][j + 1]);
				sort(b.begin(), b.end());
				ans = min(ans, b[3] - b[0]);
			}
		}
		
		cout << ans << endl;
	}

	return 0;
}