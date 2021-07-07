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

//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 100 + 5;

string name[maxn];
int att[maxn], def[maxn], hp[maxn];
bool W[maxn][maxn];

bool win(int i, int j){
	
	int hp1 = hp[i];
	int at1 = att[i];
	int df1 = def[i];
	
	int hp2 = hp[j];
	int at2 = att[j];
	int df2 = def[j];
	
	int lo = 0, hi = 100000, opt = 0;
	
	while(lo <= hi){
		int mid = (lo + hi) >> 1;
		int rm1 = hp1 - mid * max(0, at2 - df1);
		int rm2 = hp2 - mid * max(0, at1 - df2);
		
		if(rm1 > 0 && rm2 > 0){
			opt = mid;
			lo = mid + 1;
		}
		else hi = mid - 1;
	}
	
	
	hp1 -= (opt + 1) * max(at2 - df1, 0);
	hp2 -= (opt + 1) * max(at1 - df2, 0);
	
	if(hp1 > 0 && hp2 <= 0)
		return true;
	return false;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> name[i] >> hp[i] >> att[i] >> def[i];

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if(i != j)
				W[i][j] = win(i, j);
	
	set<vector<string>> ans;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(i == j)
				continue;
			for(int k = 0; k < n; k++){
				if(k == i || k == j)
					continue;
				if(W[i][j] && W[j][k] && W[k][i]){
					vector<string> v;
					v.push_back(name[i]);
					v.push_back(name[j]);
					v.push_back(name[k]);
					sort(v.begin(), v.end());
					ans.insert(v);
				}
					
			}
		}
	}
	
	cout << ans.size() << endl;
	for(auto &el : ans)
		cout << el[0] << " " << el[1] << " " << el[2] << endl;

	return 0;
}