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

bool G[11][11], must[11][11], flags[11];

vector<int> cur;

int n;
ll ans = 0;

bool ok(vector<int> &v){
	
	int cnt = 0;
	
	for(int i = 1; i < v.size(); i++){
		int x = v[i - 1], y = v[i];
		if(!G[x][y])
			return false;
		if(must[x][y])
			cnt++;
	}
	
	return cnt == n;
}

void gen(int pos, int sz){
	
	if(pos == sz)
		ans += ok(cur);
	else{
		for(int i = 1; i < 10; i++){
			if(!flags[i]){
				flags[i] = true;
				cur[pos] = i;
				gen(pos + 1, sz);
				flags[i] = false;
				cur[pos] = 0;
			}
		}
	}
	
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	cin >> n;
	
	for(int i = 0; i < 10; i++)
		for(int j = 0; j < 10; j++)
			G[i][j] = true;
	
	G[1][3] = G[3][1] = false;
	G[4][6] = G[6][4] = false;
	G[7][9] = G[9][7] = false;
	G[1][7] = G[7][1] = false;
	G[2][8] = G[8][2] = false;
	G[3][9] = G[9][3] = false;
	G[1][9] = G[9][1] = false;
	G[3][7] = G[7][3] = false;
	
	for(int i = 0; i < n; i++){
		int a, b;
		cin >> a >> b;
		must[a][b] = true;
		must[b][a] = true;
	}
	
	for(int sz = 2; sz <= 9; sz++){
		memset(flags, false, sizeof(flags));
		cur = vector<int>(sz, -1);
		gen(0, sz);
	}
		
	cout << ans << endl;
	
	return 0;
}