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

const int maxn = 300;

char a[maxn][maxn];

int pi[maxn * maxn], sz[maxn * maxn], n, m;
bool used[maxn][maxn];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void init(int N){
	for(int i = 0; i < N; i++)
		sz[pi[i] = i] = 1;
}

int root(int x){
	return x == pi[x] ? x : root(pi[x]);
}

void merge(int x, int y){
	x = root(x);
	y = root(y);
	if(x == y) return;
	if(sz[x] > sz[y]) swap(x, y);
	
	sz[y] += sz[x];
	pi[x] = y;
}

bool valid(int x, int y){
	return x >= 0 && x < n && y >= 0 && y < m;
}

int get(int x, int y){
	return x * m + y;
}

string get_string(char c){
	if(c == '0') return "0000";
	if(c == '1') return "0001";
	if(c == '2') return "0010";
	if(c == '3') return "0011";
	if(c == '4') return "0100";
	if(c == '5') return "0101";
	if(c == '6') return "0110";
	if(c == '7') return "0111";
	if(c == '8') return "1000";
	if(c == '9') return "1001";
	if(c == 'a') return "1010";
	if(c == 'b') return "1011";
	if(c == 'c') return "1100";
	if(c == 'd') return "1101";
	if(c == 'e') return "1110";
	if(c == 'f') return "1111";
	return "none";
}

int bfs(int x, int y){
	set<int> faces;
	queue<pii> Q;
	Q.push({x, y});
	used[x][y] = true;
	
	while(!Q.empty()){
		int x = Q.front().first, y = Q.front().second;
		Q.pop();
		
		for(int i = 0; i < 4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(!valid(nx, ny) || used[nx][ny]) continue;
			
			if(a[nx][ny] == '0')
				faces.insert(root(get(nx, ny)));
			else{
				used[nx][ny] = true;
				Q.push({nx, ny});
			}
				
		}
	}
	
	return faces.size();
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	
	
	int cases = 1;
	
	while(cin >> n >> m && (n + m)){
		
		
		for(int i = 0; i < maxn; i++)
			for(int j = 0; j < maxn; j++)
				a[i][j] = '0';
		
		memset(used, false, sizeof(used));
		memset(pi, 0, sizeof(pi));
		memset(sz, 0, sizeof(sz));
		
		for(int i = 2; i <= n; i++){
			for(int j = 0, k = 2; j < m; j++){
				char c;
				cin >> c;
				string x = get_string(c);
				for(int l = 0; l < 4; l++)
					a[i][k++] = x[l];
			}
		}
		
		m *= 4;
		
		n += 5;
		m += 5;
			
		init(n * m + 5);
		
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++){
				for(int k = 0; k < 4; k++){
					int nx = i + dx[k];
					int ny = j + dy[k];
					if(valid(nx, ny) && a[i][j] == a[nx][ny])
						merge(get(i, j), get(nx, ny));
				}
			}
		
		string ans = "";
		
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++){
				if(a[i][j] == '1' && !used[i][j]){
					int comps = bfs(i, j);
					if(comps == 1)
						ans += "W";
					if(comps == 2)
						ans += "A";
					if(comps == 3)
						ans += "K";
					if(comps == 4)
						ans += "J";
					if(comps == 5)
						ans += "S";
					if(comps == 6)
						ans += "D";
				}
			}
		
		sort(ans.begin(), ans.end());
		
		cout << "Case " << cases++ << ": " << ans << endl;
	}

	return 0;
}