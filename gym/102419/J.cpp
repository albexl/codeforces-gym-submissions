#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <random>
#include <chrono>
 
using namespace std;
using namespace __gnu_pbds;
 
#define endl '\n'
 
typedef long long ll;
typedef pair<ll, ll> pii;
typedef tree<int, null_type,less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
template<typename T>
static T randint(T lo, T hi){
	return uniform_int_distribution<T>(lo, hi)(rng);
}



int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	// freopen("dislodging_logs_input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	int n, m;
	cin >> n >> m;

	vector<int> onesR(n), onesC(m);
	vector<bool> fr(n), fc(m);
	for(int i = 0; i < n; i++)
		cin >> onesR[i];

	vector<vector<int>> a(n, vector<int>(m));
	int cnt = 0;
	vector<pair<string, int>> ans;

	int j = 1;
	for(int i = 0; i < n; i++){
		if(onesR[i] == 0)
			continue;

		int cnt = onesR[i];

		a[i][0] = 1;
		onesC[0]++;
		cnt--;

		while(cnt--){
			if(j == m){
				cout << "NO" << endl;
				return 0;
			}

			a[i][j] = 1;
			onesC[j]++;
			j++;
		}
	}	

	vector<vector<int>> b = a;

	queue<pair<string, int>> Q;
	for(int i = 0; i < n; i++)
		if(onesR[i] <= 1){
			fr[i] = true;
			Q.push({"row", i});
		}

	for(int j = 0; j < m; j++)
		if(onesC[j] <= 1){
			fc[j] = true;
			Q.push({"col", j});
		}

	while(!Q.empty()){
		string lab = Q.front().first;
		int x = Q.front().second;
		Q.pop();
		cnt++;

		ans.push_back({lab, x});

		if(lab == "row"){
			for(int j = 0; j < m; j++){
				if(a[x][j] == 1){
					onesC[j]--;
					a[x][j] = 0;

					if(!fc[j] && onesC[j] <= 1){
						Q.push({"col", j});
						fc[j] = true;
					}
				}
			}
		}
		else{
			for(int i = 0; i < n; i++){
				if(a[i][x] == 1){
					onesR[i]--;
					a[i][x] = 0;

					if(!fr[i] && onesR[i] <= 1){
						Q.push({"row", i});
						fr[i] = true;
					}
				}
			}
		}
	}

	if(cnt != n + m){
		cout << "NO" << endl;
	}
	else{
		cout << "YES" << endl;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cout << b[i][j];
			cout << endl;
		}
		for(auto &el : ans)
			cout << el.first << " " << el.second + 1 << endl;
	}

	return 0;
}