#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define MAX

typedef long long ll;
typedef pair<ll, int> pii;
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;



int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n;
	cin >> n;

	map<int, vector<int>> mp;

	for(int i = 0; i < n; i++){
		int x, y;
		cin >> x >> y;
		mp[x].push_back(y);
	}

	int N = (int)mp.size();

	vector<vector<int>> NUM(N, vector<int>(4, -1));

	int idx = 0;

	for(auto &p : mp){

		auto v = p.second;
		sort(v.begin(), v.end());

		NUM[idx][3] = v.back();
		v.pop_back();

		if(!v.empty()){
			NUM[idx][2] = v.back();
			v.pop_back();
		}

		if(!v.empty()){
			NUM[idx][0] = v[0];
		}

		if((int)v.size() >= 2){
			NUM[idx][1] = v[1];
		}

		idx++;

	}

	
	vector<vector<ll>> dp(N, vector<ll>(4));

	for(int i = 1; i < N; i++){

		vector<pii> prv;

		for(int j = 0; j < 4; j++)
			if(NUM[i - 1][j] != -1)
				prv.push_back(pii(dp[i - 1][j], j));

		sort(prv.rbegin(), prv.rend());

		for(int j = 0; j < 4; j++){

			int x = NUM[i][j];
			if(x == -1)
				continue;

			for(int k = 0; k < 4; k++){

				int y = NUM[i - 1][k];
				if(y == -1)
					continue;

				ll mx = prv[0].first;
				if(prv[0].second == k && (int)prv.size() > 1)
					mx = prv[1].first;


				dp[i][j] = max(dp[i][j], mx + 1ll * abs(x - y));

			}

		}
	}

	ll ans = 0;

	for(int i = 0; i < 4; i++)
		if(NUM[N - 1][i] != -1)
			ans = max(ans, dp[N - 1][i]);

	cout << ans << endl;

	return 0;
}

/*

6
4 1
4 3
3 2
2 2
1 3
1 1

*/