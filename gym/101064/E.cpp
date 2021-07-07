#include<bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define MAX
 
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii> tri;
 
const int S = 305, MAXC = 12;
const int oo = 0x3f3f3f3f;
 
int go[S][MAXC];
int fail[S], final[S];
int idx = 2;
 
void insert(string s, int p){
	int node = 1;
	int n = s.size();
	for(int i = 0; i < n; i++){
		if(!go[node][s[i] - 'a'])
			go[node][s[i] - 'a'] = idx++;
		node = go[node][s[i] - 'a'];
	}
	final[node] |= (1 << p);
}
 
void build_AC(){
	queue<int> Q;
	
	for(int i = 0; i < MAXC; i++){
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
tri pi[S][1 << 15];
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 	
	int N, M;
	cin >> N >> M;

	for(int i = 0; i < N; i++){
		string s;
		cin >> s;
		insert(s, i);
	}

	for(int i = 0; i < M; i++){
		string s;
		cin >> s;
		insert(s, i + N);
	}
	
	build_AC();
	
	for(int i = 0; i < S; i++){
		for(int j = 0; j < (1 << (N + M)); j++){
			dp[i][j] = -1;
			pi[i][j] = {-1, {-1, -1}};
		}
	}
	
	queue<pii> Q;
	dp[1][0] = 0;
	Q.push({1, 0});
	
	while(!Q.empty()){
		int u, mask;
		tie(u, mask) = Q.front();Q.pop();

		for(int i = 0; i < MAXC; i++){
			int v = go[u][i];
			int m = mask | final[v];
			
			bool f = true;
			for(int j = N; f && j < N + M; j++){
				if(m & (1 << j))
					f = false;
			}

			if(!f)
				continue;
			
			if(dp[v][m] == -1){
				dp[v][m] = 1 + dp[u][mask];
				pi[v][m] = {u, {i, mask}};
				Q.push({v, m});
			}
		}
	}
	
	int solve = oo;
	int node = -1;

	for(int i = 1; i < S; i++)
		if(dp[i][(1 << N) - 1] != -1 && solve > dp[i][(1 << N) - 1]){
			solve = dp[i][(1 << N) - 1];
			node = i;
		}
	
	
	if(node == -1){
		cout << "-" << endl;
		return 0;
	}
	
	string ans = "";
	int mask = (1 << N) - 1;
	
	//cout << solve << " " << node << " " << mask << endl;
	
	while(node != 1){
		ans += (char)(pi[node][mask].second.first + 'a');
		int new_mask = pi[node][mask].second.second;
		int new_node = pi[node][mask].first;
		node = new_node;
		mask = new_mask;
	//	cout << node << " " << mask << " " << ans << endl;
	}
	
	reverse(ans.begin(),ans.end());
	cout << ans << endl;
 
	
	return 0;
}