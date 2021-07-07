#include <bits/stdc++.h>

using namespace std;

// #define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;


struct segment_tree{

	vector<vector<int>> st;

	void build(int n, vector<pii> &v){
		st.resize(4 * n);
		build(1, 0, n - 1, v);
	}

	void build(int node, int b, int e, vector<pii> &v){

		if(b == e)
			st[node].push_back(v[b].second);
		else{
			int m = (b + e) >> 1;
			int l = node << 1;
			int r = l | 1;

			build(l, b, m, v);
			build(r, m + 1, e, v);

			st[node].resize(e - b + 1);
			merge(st[l].begin(), st[l].end(), st[r].begin(), st[r].end(), st[node].begin());
		}	
	}

	int get_ans(int node, int x){

		auto pos = upper_bound(st[node].begin(), st[node].end(), x);
		if(pos == st[node].begin())
			return -1;
		return *prev(pos);
	}

	int query(int node, int b, int e, int i, int j, int x){
		if(b >= i && e <= j)
			return get_ans(node, x);
		if(b > j || e < i)
			return -1;

		int m = (b + e) >> 1;
		int l = node << 1;
		int r = l | 1;

		int L = query(l, b, m, i, j, x);
		int R = query(r, m + 1, e, i, j, x);

		return max(L, R);
	}

};

const int maxn = 3e5 + 5;

int lo[maxn], hi[maxn], inv[2 * maxn], t = 1, n;
vector<int> g[maxn];

map<string, vector<pii>> mp;
map<string, string> props[maxn];
map<string, segment_tree> st;

void dfs(int u, int p){
	lo[u] = t;
	inv[t] = u;
	t++;
	for(auto &v : g[u])
		if(v != p)
			dfs(v, u);
	hi[u] = t++;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 1; i <= n; i++){
    	int p, k;
    	cin >> p >> k;

    	if(p)
    		g[p].push_back(i);

    	for(int j = 0; j < k; j++){
    		string s;
    		cin >> s;

    		string x = "", y = "";
    		
    		int pos = 0;
    		while(s[pos] != '=')
    			x += s[pos++];

    		pos++;
    		while(pos < s.size())
    			y += s[pos], pos++;

    		props[i][x] = y;
    	}
    }
    
    dfs(1, 0);

    for(int i = 1; i <= n; i++)
    	for(auto &val : props[i])
    		mp[val.first].push_back({hi[i], lo[i]});

    for(auto &el : mp){
    	sort(el.second.begin(), el.second.end());
    	st[el.first].build((int)el.second.size(), el.second);
    }
    

    int q; 
    cin >> q;
    while(q--){

    	int u;
    	string p;
    	cin >> u >> p;

    	if(mp.find(p) == mp.end())
    		cout << "N/A" << endl;
    	else{
    		vector<pii> &vals = mp[p];

	    	int r = vals.size() - 1;
	    	auto pos = lower_bound(vals.begin(), vals.end(), pii(hi[u], 0));

	    	if(pos == vals.end())
	    		cout << "N/A" << endl;
	    	else{
	    		int ans = st[p].query(1, 0, r, pos - vals.begin(), r, lo[u]);

	    		if(ans == -1)
	    			cout << "N/A" << endl;
	    		else{
	    			int node = inv[ans];
					cout << props[node][p] << endl;
				}
	    	}
    	}
    	
    	// fflush(stdout);
    }

    return 0;
}