#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 2000 + 5;
const int oo = 0x3f3f3f3f;

vector<int> g[maxn];
//int G[maxn][maxn];
int n, m;

int cnt = 0;

int bfs(int s){
	vector<int> d(n, -1);
	d[s] = 0;
	queue<int> Q;
	Q.push(s);
	int last = -1;
	cnt = 0;

//	cout << s << " :" << endl;


	while(!Q.empty()){
		cnt++;
		int x = Q.front();Q.pop();
		last = x;


//		cout << x << " " << d[x] << endl;

		for(auto &y : g[x]){
			if(d[y] == -1){
				d[y] = d[x] + 1;
				Q.push(y);
			}
		}
	}


	return d[last];
}

int diameter(){
	int ans = -1;
	for(int i = 0; i < n; i++)
		ans = max(ans, bfs(i));
	return ans;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

//	srand(time(0));

	cin >> n >> m;
//
//	n = rand() % 10 + 1;
//	m = rand() % (n * (n - 1) / 2);
//	memset(G, oo, sizeof(G));
//
//	cout << n << " " << m << endl;
//
//	for(int i = 0; i < n; i++)
//		G[i][i] = 0;

	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		a--, b--;

//		while(true){
//			a = rand() % n;
//			b = rand() % n;
//			if(a != b)
//				break;
//		}

//		cout << a << " " << b << endl;

		g[a].push_back(b);
		g[b].push_back(a);

//		G[a][b] = G[b][a] = 1;
	}

	int ans = diameter();

	if(cnt != n)
		cout << "=[" << endl;
	else
		cout << "=] " << ans << endl;


//	for(int k = 0; k < n; k++)
//		for(int i = 0; i < n; i++)
//			for(int j = 0; j < n; j++)
//				G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
//
//
//
//	for(int i = 0; i < n; i++)
//		for(int j = 0; j < n; j++)
//			cout << G[i][j] << " \n"[j + 1 == n];
//	cout << endl;
//
//	bool con = true;
//	int mx = -1;
//	for(int i = 0; i < n; i++)
//		for(int j = 0; j < n; j++){
//			if(G[i][j] > 100)
//				con = false;
//			mx = max(mx, G[i][j]);
//		}
//
//	if(!con)
//		cout << "=[" << endl;
//	else
//		cout << "=] " << mx << endl;

	return 0;
}

/*
 *
10 21
5 6
8 2
9 7
1 2
7 3
0 4
4 2
0 5
5 2
5 0
1 9
8 4
9 3
3 2
3 4
9 0
1 9
7 6
6 4
1 7
0 5
 */