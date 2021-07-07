#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <random>
#include <chrono>

using namespace std;
using namespace __gnu_pbds;

//#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;
//typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;

//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<string> a = {
	"............",
	"............",
	"..x......x..",
	"............",
	"............",
	".....##.....",
	".....##.....",
	"............",
	".##......##.",
	".#x......x#.",
	"............",
	"............"

};

int d[15][15];
pii pi[15][15];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool valid(int x, int y){
	return x >= 0 && x < 12 && y >= 0 && y < 12;
}

void bfs(){
	
	vector<pii> start;
	
	for(int i = 0; i < 12; i++)
		for(int j = 0; j < 12; j++){
			d[i][j] = -1;
			pi[i][j] = {-1, -1};
			if(a[i][j] == 'x')
				start.push_back({i, j});
		}
	
	queue<pii> Q;
	
	for(auto &p : start){
		Q.push(p);
		d[p.first][p.second] = 0;
	}
	
	while(!Q.empty()){
		
		int x = Q.front().first;
		int y = Q.front().second;
		Q.pop();
		
		for(int i = 0; i < 4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(valid(nx, ny) && a[nx][ny] != '#' && d[nx][ny] == -1){
				Q.push({nx, ny});
				d[nx][ny] = d[x][y] + 1;
				pi[nx][ny] = {x, y};
			}
		}
		
	}
	
	
}

string get_dir(int x, int y, int xo, int yo){
	if(xo < x)
		return "U";
	if(xo > x)
		return "D";
	if(yo < y)
		return "L";
	return "R";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	int t;
	cin >> t;
	while(t--){
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		
		bfs();
		
		string path = "";
		
		while(a[x][y] != 'x'){
			
			//cout << x << " " << y << endl;
			
			path += get_dir(x, y, pi[x][y].first, pi[x][y].second);
			auto aux = pi[x][y];
			x = aux.first;
			y = aux.second;
		}
		
		cout << path.size() << endl;
		cout << path << endl;
	}

	return 0;
}