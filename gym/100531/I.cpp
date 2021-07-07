#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
 
typedef long long ll;
typedef pair<ll, int> pii;

 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("instruction.in", "r", stdin);
    freopen("instruction.out", "w", stdout);

    
    int n;
    cin >> n;

    vector<vector<int>> g(1);
    vector<int> pi(1, -1);

    map<string, int> mp;

    for(int i = 1; i <= n; i++){

    	// cerr << i << " :" << endl;

    	string op;
    	cin >> op;

    	int v;
		cin >> v;
		g[v].push_back(i);
		pi.push_back(v);

    	if(op == "p"){
    		string name;
    		cin >> name;
    		mp[name] = i;
    	}

    	g.push_back({});
    }

    int N = g.size();

    for(int i = 0; i < N; i++)
    	sort(g[i].begin(), g[i].end());

    vector<bool> left(N, true);
    vector<pii> ans;

    int q;
    cin >> q;

    while(q--){

    	int t;
    	string name;

    	cin >> t >> name;

    	int u = mp[name];

    	vector<int> path;

    	while(u){
    		path.push_back(u);
    		u = pi[u];
    	}

    	reverse(path.begin(), path.end());

    	for(int i = 0; i + 1 < path.size(); i++){
    		int u = path[i], v = path[i + 1];

    		if(g[u][0] == v && left[u])
    			continue;
    		if(g[u][1] == v && !left[u])
    			continue;

    		left[u] = !left[u];
    		ans.push_back({t + i + 1, u});
    	}
    }

    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for(auto &el : ans)
    	cout << el.second << " " << el.first << endl;

    return 0;
}