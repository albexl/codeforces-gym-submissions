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

const int maxn = 900 + 5;

char a[maxn][maxn];
int d[maxn][maxn];
int n, m;

//			U   R  D  L
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

bool valid(int x, int y){
	return x >= 0 && x < 2 * n - 1 && y >= 0 && y < 2 * m - 1;
}

bool good(int x, int y, int nx, int ny){
	int addx = 0, addy = 0;
	if(x != nx){
		if(nx > x)
			addx = 1;
		else
			addx = -1;
	}
	else{
		if(ny > y)
			addy = 1;
		else
			addy = -1;
	}
		
	if(valid(nx, ny) && d[x][y] == d[nx][ny] + 1 && a[x + addx][y + addy] != ' ')
		return true;
	return false;
}

string simulate(int x, int y, int dir){
	
	string ans = "";
	ans += ( (dir == 0) ? "N" : "E");
	
	while(x != 0 || y != 2 * m - 2){
		
		int nx = x + 2 * dx[dir];
		int ny = y + 2 * dy[dir];
		
		if(good(x, y, nx, ny)){
			ans += "F";
			x = nx;
			y = ny;
			continue;
		}
		
		int pos = (dir + 1) % 4;
		nx = x + 2 * dx[pos];
		ny = y + 2 * dy[pos];
		
		if(good(x, y, nx, ny)){
			ans += "R";
			x = nx;
			y = ny;
			dir = pos;
			continue;
		}
		
		pos = (dir - 1 + 4) % 4;
		nx = x + 2 * dx[pos];
		ny = y + 2 * dy[pos];
		
		if(good(x, y, nx, ny)){
			ans += "L";
			x = nx;
			y = ny;
			dir = pos;
			continue;
		}
	}
	
	return ans;
}

void print(string s){
	cout << s[0] << endl;
	for(int i = 1; i < s.size(); i++)
		cout << s[i];
	cout << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	freopen("straight.in", "r", stdin);
	freopen("straight.out", "w", stdout);
	
	cin >> n >> m;
	
	string s;
	getline(cin, s);
	
	for(int i = 0; i < 2 * n - 1; i++){
		getline(cin, s);
		for(int j = 0; j < 2 * m - 1; j++)
			a[i][j] = s[j];
	}
	
	memset(d, -1, sizeof(d));
	d[0][2 * m - 2] = 0;
	queue<pii> Q;
	Q.push({0, 2 * m - 2});
	while(!Q.empty()){
		int x = Q.front().first;
		int y = Q.front().second;
		Q.pop();
		
		if(y - 2 >= 0 && a[x][y - 1] != ' ' && d[x][y - 2] == -1){
			d[x][y - 2] = d[x][y] + 1;
			Q.push({x, y - 2});
		}
		
		if(y + 2 < 2 * m - 1 && a[x][y + 1] != ' ' && d[x][y + 2] == -1){
			d[x][y + 2] = d[x][y] + 1;
			Q.push({x, y + 2});
		}
		
		if(x - 2 >= 0 && a[x - 1][y] != ' ' && d[x - 2][y] == -1){
			d[x - 2][y] = d[x][y] + 1;
			Q.push({x - 2, y});
		}
		
		if(x + 2 < 2 * n - 1 && a[x + 1][y] != ' ' && d[x + 2][y] == -1){
			d[x + 2][y] = d[x][y] + 1;
			Q.push({x + 2, y});
		}
	}
	
	int xo = 2 * n - 2, yo = 0;
	
	string s1 = "", s2 = "";
	if(d[xo - 2][yo] == d[xo][yo] - 1 && a[xo - 1][yo] != ' ')
		s1 = simulate(xo - 2, yo, 0);
	if(d[xo][yo + 2] == d[xo][yo] - 1 && a[xo][yo + 1] != ' ')
		s2 = simulate(xo, yo + 2, 1);

	if(s1 == "")
		print(s2);
	else if(s2 == "")
		print(s1);
	else if(s1.size() < s2.size())
		print(s1);
	else
		print(s2);
	
	return 0;
}