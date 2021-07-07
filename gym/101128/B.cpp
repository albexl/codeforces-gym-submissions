#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;

struct satisfiability_twosat
{
	int n;
	vector<vector<int>> imp;

	satisfiability_twosat(int n) : n(n), imp(2 * n) {}

	void add_edge(int u, int v)
	{
		imp[u].push_back(v);
	}

	int neg(int u) { return (n << 1) - u - 1; }

	void implication(int u, int v)
	{
		add_edge(u, v);
		add_edge(neg(v), neg(u));
	}

	vector<bool> solve()
	{
		int size = 2 * n;
		vector<int> S, B, I(size);

		function<void(int)> dfs = [&](int u)
		{
			B.push_back(I[u] = S.size());
			S.push_back(u);

			for (int v : imp[u])
				if (!I[v]) dfs(v);
				else while (I[v] < B.back()) B.pop_back();

			if (I[u] == B.back())
				for (B.pop_back(), ++size; I[u] < S.size(); S.pop_back())
					I[S.back()] = size;
		};

		for (int u = 0; u < 2 * n; ++u)
			if (!I[u]) dfs(u);

		vector<bool> values(n);

		for (int u = 0; u < n; ++u)
			if (I[u] == I[neg(u)]) return {};
			else values[u] = I[u] < I[neg(u)];

		return values;
	}
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    int n;
    cin >> n;

    vector<pair<string, pii>> V(n);
    for(int i = 0; i < n; i++)
    	cin >> V[i].first >> V[i].second.first >> V[i].second.second;

    int ans = 0;

    for(int i = 0; i < 26; i++){
    	for(int j = i + 1; j < 26; j++){
    		for(int k = j + 1; k < 26; k++){
    			satisfiability_twosat ts(52);

    			//not black vienna
    			for(int m = 0; m < 26; m++){
    				if(m != i && m != j && m != k){
    					int u = m, v = u + 26;
    					ts.implication(u, ts.neg(v));
    					ts.implication(ts.neg(u), v);
    				}
    			}

    			//black vienna
    			int u = i, v = i + 26;
    			ts.implication(u, ts.neg(u));
    			ts.implication(v, ts.neg(v));

    			u = j, v = j + 26;
    			ts.implication(u, ts.neg(u));
    			ts.implication(v, ts.neg(v));

    			u = k, v = k + 26;
    			ts.implication(u, ts.neg(u));
    			ts.implication(v, ts.neg(v));

    			//rules
    			for(auto &s : V){
    				string x = s.first;
    				int p = s.second.first;
    				int r = s.second.second;

    				int u = x[0] - 'A';
    				int v = x[1] - 'A';

    				if(p == 2)
    					u += 26, v += 26;

    				if(r == 0){
    					ts.implication(u, ts.neg(u));
    					ts.implication(v, ts.neg(v));
    				}

    				if(r == 1){
    					ts.implication(u, ts.neg(v));
    					ts.implication(ts.neg(u), v);
    				}

    				if(r == 2){
    					ts.implication(ts.neg(u), u);
    					ts.implication(ts.neg(v), v);
    				}
    			}

    			auto D = ts.solve();
    			if(!D.empty())
    				ans++;
    		}
    	}
    }

    cout << ans << endl;

    return 0;
}