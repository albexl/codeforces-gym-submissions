#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;

template<typename T>
struct dinic
{
	struct edge
	{
		int src, dst;
		T cap, flow;
		int rev;
	};

	int n;
	vector<vector<edge>> adj;

	dinic(int n) : n(n), adj(n) {}

	void add_edge(int src, int dst, T cap)
	{
		adj[src].push_back({ src, dst, cap, 0, (int) adj[dst].size() });
		if (src == dst)
			adj[src].back().rev++;
		adj[dst].push_back({ dst, src, 0, 0, (int) adj[src].size() - 1 });
	}

	vector<int> level, iter;

	T augment(int u, int t, T cur)
	{
		if (u == t)
			return cur;
		for (int &i = iter[u]; i < (int) adj[u].size(); ++i)
		{
			edge &e = adj[u][i];
			if (e.cap - e.flow > 0 && level[u] > level[e.dst])
			{
				T f = augment(e.dst, t, min(cur, e.cap - e.flow));
				if (f > 0)
				{
					e.flow += f;
					adj[e.dst][e.rev].flow -= f;
					return f;
				}
			}
		}
		return 0;
	}

	int bfs(int s, int t)
	{
		level.assign(n, n);
		level[t] = 0;
		queue<int> Q;
		for (Q.push(t); !Q.empty(); Q.pop())
		{
			int u = Q.front();
			if (u == s)
				break;
			for (edge &e : adj[u])
			{
				edge &erev = adj[e.dst][e.rev];
				if (erev.cap - erev.flow > 0
					&& level[e.dst] > level[u] + 1)
				{
					Q.push(e.dst);
					level[e.dst] = level[u] + 1;
				}
			}
		}
		return level[s];
	}

	const T oo = numeric_limits<T>::max();

	T max_flow(int s, int t)
	{
		for (int u = 0; u < n; ++u) // initialize
			for (auto &e : adj[u])
				e.flow = 0;

		T flow = 0;
		while (bfs(s, t) < n)
		{
			iter.assign(n, 0);
			for (T f; (f = augment(s, t, oo)) > 0;)
				flow += f;
		} // level[u] == n ==> s-side
		return flow;
	}
};


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int k, n, a, b;
    cin >> k >> n >> a >> b;

    vector<int> A(a), B(b);
    vector<bool> fa(k), fb(k);
    vector<vector<int>> sum(k, vector<int>(k));
    vector<int> v(n), g(n - 1);

    for(int i = 0; i < a; i++){
    	cin >> A[i], A[i]--;
    	fa[A[i]] = true;
    }

    for(int i = 0; i < b; i++){
    	cin >> B[i], B[i]--;
    	fb[B[i]] = true;
    }

    for(int i = 0; i < n; i++)
    	cin >> v[i], v[i]--;

    int total = 0;
    for(int i = 0; i < n - 1; i++){
    	cin >> g[i];
    	sum[v[i]][v[i + 1]] += g[i];
    	sum[v[i + 1]][v[i]] += g[i];
    	total += g[i];
    }

    dinic<int> mf(k + 2);
    int s = k, t = s + 1;

    const int oo = numeric_limits<int>::max();

    for(int i = 0; i < k; i++){
    	for(int j = i + 1; j < k; j++){
    		mf.add_edge(i, j, sum[i][j]);
    		mf.add_edge(j, i, sum[i][j]);
    	}
    }

    for(int i = 0; i < a; i++)
    	if(!fb[A[i]])
    		mf.add_edge(s, A[i], oo);
    
    for(int i = 0; i < b; i++)
    	if(!fa[B[i]])
    		mf.add_edge(B[i], t, oo);

    cout << total - mf.max_flow(s, t) << endl;

    return 0;
}