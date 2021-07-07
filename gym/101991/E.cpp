#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;

const int S = 1e5 + 5, MAXC = 26;

int go[S][MAXC], fail[S], len[S], A[S], C[S];
int idx = 2;

void clean(){

	for(int i = 0; i < idx; i++){
		len[i] = fail[i] = A[i] = C[i] = 0;
		for(int j = 0; j < MAXC; j++)
			go[i][j] = 0;
	}
	idx = 2;
}

void insert(string s, vector<int> &a){
	int node = 1;
	int n = (int)s.size();
	for(int i = 0; i < n; i++){
		if(!go[node][s[i] - 'a'])
			go[node][s[i] - 'a'] = idx++;
		node = go[node][s[i] - 'a'];
		C[node]++;
		len[node] = i + 1;
		A[node] = max(a[i], A[node]);
	}
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
				Q.push(go[u][i]);
			}
		}
	}
}


int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

    freopen("exciting.in", "r", stdin);

	int t;
	cin >> t;

	while(t--){
		int n;
		cin >> n;

		vector<string> v(n);
		vector<vector<int>> a(n);

		for(int i = 0; i < n; i++)
			cin >> v[i];

		for(int i = 0; i < n; i++){
			int sz = (int)v[i].size();
			a[i].resize(sz);
			for(int j = 0; j < sz; j++)
				cin >> a[i][j];
		}

		for(int i = 0; i < n; i++)
			insert(v[i], a[i]);

		build_AC();
		
        vector<pii> e;
        for(int i = 2; i < idx; i++)
            e.push_back({len[i], i});
            
        sort(e.rbegin(), e.rend());
        for(auto &x : e){
            int node = x.second;
            A[fail[node]] = max(A[fail[node]], A[node]);
        }
        
		ll ans = 0;
		for(int i = 1; i < idx; i++){
// 			cout << i << " " << C[i] << " " << len[i] << " " << A[i] << endl;
			ans = max(ans, 1ll * C[i] * len[i] * A[i]);
        }
        
		cout << ans << endl;
        if(t)
		    clean();
	}

	return 0;
}