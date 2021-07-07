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

vector<pair<string, pii>> moves = { {"A", {-1, -2}}, {"B", {-2, -1}}, {"C", {-2, +1}}, {"D", {-1, +2}}, {"E", {+1, +2}}, {"F", {+2, +1}}, {"G", {+2, -1}}, {"H", {+1, -2}}};

const int maxn = 1000 + 5;

int n, m;
int d[maxn][maxn];
pair<string, pii> pi[maxn][maxn];
char a[maxn][maxn];

bool valid(int x, int y){
	return x >= 0 && x < n && y >= 0 && y < m;	
}


void bfs(int x, int y){
	queue<pii> Q;
	Q.push({x, y});
	memset(d, -1, sizeof(d));
	d[x][y] = 0;
	
	while(!Q.empty()){
		x = Q.front().first;
		y = Q.front().second;
		Q.pop();
		
		for(auto &m : moves){
			string p = m.first;
			int nx = x + m.second.first;
			int ny = y + m.second.second;
			
			if(valid(nx, ny) && a[nx][ny] != 'X' && d[nx][ny] == -1){
				d[nx][ny] = d[x][y] + 1;
				Q.push({nx, ny});
				pi[nx][ny] = {p, {x, y}};
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	int t;
	cin >> t;
	
	while(t--){
		cin >> n >> m;
		for(int i = 0; i < n; i++)
			cin >> a[i];
		
		int xo = -1, yo = -1, xe = -1, ye = -1;
		
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++){
				if(a[i][j] == 'K')
					xo = i, yo = j;
				if(a[i][j] == 'F')
					xe = i, ye = j;
			}
		
		bfs(xo, yo);
		
		if(d[xe][ye] != -1){
			cout << "Whinny" << endl;
			string ans = "";
			while(xe != xo || ye != yo){
				auto prv = pi[xe][ye];
				ans += prv.first;
				xe = prv.second.first;
				ye = prv.second.second;
			}
			reverse(ans.begin(), ans.end());
			cout << ans << endl;
		}
		else
			cout << "Neigh" << endl;
	}

	return 0;
}