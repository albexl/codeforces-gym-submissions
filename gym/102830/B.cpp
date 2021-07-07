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
// typedef tree<int, null_type,less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
// template<typename T>
// static T randint(T lo, T hi){
// 	return uniform_int_distribution<T>(lo, hi)(rng);
// }



int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	// freopen("settling.in", "r", stdin);
	// freopen("settling.out", "w", stdout);

	int n;
	cin >> n;

	vector<vector<bool>> a(30, vector<bool>(30));
	for(int i = 0; i < n; i++){
		int x, y;
		cin >> x >> y;
		a[x][y] = true;
	}

	int ans = 0;
	vector<int> dx = {1, -1, 0, 0};
	vector<int> dy = {0, 0, 1, -1};

	for(int i = 0; i < 26; i++){
		for(int j = 0; j < 26; j++){
			if(a[i][j]){
				int cnt = 0;
				for(int k = 0; k < 4; k++){
					int ii = i + dx[k];
					int jj = j + dy[k];
					if(ii >= 0 && ii < 26 && jj >= 0 && jj < 26 && a[ii][jj])
						cnt++;
				}

				if(cnt == 4)
					ans++;
			}
		}
	}

	cout << ans << endl;

	return 0;
}