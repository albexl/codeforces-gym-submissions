#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;

const int S = 1500 + 10, MAXC = 1500 + 10; //S = suma de las longitudes de todas las cadenas,MAXC = size del alfabeto

int go[S][MAXC];
int fail[S], final[S];
int idx = 2;

map<int, int> P;
int qq = 0;

void insert(vector<int> &s, int p){
	int node = 1;
	int n = (int)s.size();
	
	for(int i = 0; i < n; i++){
	    int x = P[s[i]];
	    
		if(!go[node][x])
			go[node][x] = idx++;
			
		node = go[node][x];
	}
	
	final[node] |= (1 << p);
}

void build_AC(){
	queue<int> Q;
	
	for(int i = 0; i < qq; i++){
		if(!go[1][i])
			go[1][i] = 1;
		else
			Q.push(go[1][i]), fail[go[1][i]] = 1;
	}
	
	fail[1] = 1;
	
	while(!Q.empty()){
		int u = Q.front();Q.pop();
		int f = fail[u];
		for(int i = 0; i < MAXC; i++){
			if(!go[u][i])
				go[u][i] = go[f][i];
			else{
				fail[go[u][i]] = go[f][i];
				final[go[u][i]] |= final[go[f][i]];
				Q.push(go[u][i]);
			}
		}
	}
}

int dp[S][1 << 15];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<vector<int>> v(n);
	
	for(int i = 0; i < n; i++){
	    int sz;
	    cin >> sz;
	    
	    v[i].resize(sz);
	    
	    for(int j = 0; j < sz; j++){
	        cin >> v[i][j];
	        if(P.find(v[i][j]) == P.end()){
	            P[v[i][j]] = qq++;
	        }
	    }
	        
	}
	
	for(int i = 0; i < n; i++)
		insert(v[i], i);
	
	memset(dp,-1,sizeof(dp));
	build_AC();
	
	queue<pii> Q;
	dp[1][0] = 0;
	Q.push({1,0});
	
	int solve = 10000000;
	
	while(!Q.empty()){
		int u,mask;
		tie(u,mask) = Q.front();Q.pop();
		
		if(mask == (1 << n) - 1)
		    solve = min(solve, dp[u][mask]);
		
		for(int i = 0; i < qq; i++){
			int v = go[u][i];
			int m = mask | final[v];
			if(dp[v][m] == -1){
				dp[v][m] = 1 + dp[u][mask];
				Q.push({v,m});
			}
		}
	}
	
	cout << solve << endl;

	return 0;
}