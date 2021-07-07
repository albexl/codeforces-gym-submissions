#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<ll, ll> pii;
typedef pair<ll, pii> tri;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

template<typename T>
static T randint(T lo, T hi) { return uniform_int_distribution<T>(lo, hi)(rng); }

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll m;
    int n;

    cin >> m >> n;

    vector<vector<int>> g(n + 1);
    vector<ll> dp(n + 1);
    vector<int> indeg(n + 1);
    vector<char> s(n + 1);

    for(int i = 1; i <= n; i++){
    	cin >> s[i];
    	int l, r;
    	cin >> l >> r;
    	g[i].push_back(l);
    	g[i].push_back(r);
    	indeg[l]++;
    	indeg[r]++;
    }

    queue<int> q;
    for(int i = 0; i <= n; i++)
    	if(indeg[i] == 0)
    		q.push(i);

    dp[1] = m;

    while(!q.empty()){
    	int u = q.front();q.pop();

    	if(u == 0)
    		break;

    	for(auto &v : g[u]){
    		indeg[v]--;
    		if(indeg[v] == 0)
    			q.push(v);
    	}

 		ll mid = dp[u] / 2;
		if(dp[u] % 2 == 0){
			dp[g[u][0]] += mid; 
			dp[g[u][1]] += mid;
		}
		else{
			if(s[u] == 'L'){
				dp[g[u][0]] += mid + 1;
				dp[g[u][1]] += mid;
			}
			else{
				dp[g[u][0]] += mid;
				dp[g[u][1]] += mid + 1;
			}
		}
    }
 
    for(int i = 1; i <= n; i++){
    	if(dp[i] % 2 == 0)
    		cout << s[i];
    	else
    		cout << (s[i] == 'L' ? 'R' : 'L');
    }

    cout << endl;

    return 0;
}