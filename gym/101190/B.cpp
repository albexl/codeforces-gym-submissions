#include <bits/stdc++.h>

using namespace std;

#ifdef DGC
#include "debug.h"
#else
#define debug(...)
#endif
typedef long long ll;
typedef long double ld;
typedef complex<ll> point;
#define F first
#define S second

struct node
{
	int id;
	vector<int> cid;
	node* ch[2];

	node() { ch[0]=ch[1]=NULL; }

	void print()
	{
		debug(id, cid, (ch[0]?ch[0]->id:0), (ch[1]?ch[1]->id:0))
	}
};

vector<node*> nodes;

node* new_node()
{
	nodes.push_back(new node());
	nodes.back()->id = nodes.size()-1;
	return nodes.back();
}

struct sat2
{
	int n;
	vector<vector<int>> adj, radj;

	sat2(int n) : n(n), adj(2*n), radj(2*n) {}

	void add_edge(int u, int v)
	{
		adj[u].push_back(v);
		radj[v].push_back(u);
	}

	int neg(int u)
	{
		return 2*n-u-1;
	}

	void implication(int u, int v)
	{
		add_edge(u, v);
		add_edge(neg(v), neg(u));
	}

	vector<bool> value;

	bool solve()
	{
		vector<int> seen(2 * n);
		value.assign(2 * n, false);

		function<void(int, vector<vector<int>>&, vector<int>&)> visit =
				[&](int u, vector<vector<int>> &adj, vector<int> &vec)
		{
			seen[u] = true;
			for (int v : adj[u])
				if (!seen[v])
					visit(v, adj, vec);
			vec.push_back(u);
		};

		vector<int> order;

		for (int u = 0; u < n; ++u)
		{
			if (!seen[u]) visit(u, adj, order);
			if (!seen[neg(u)]) visit(neg(u), adj, order);
		}

		seen.assign(2 * n, false);
		reverse(order.begin(), order.end());

		vector<int> comp, id(2 * n);
		int cc = 0;

		for (int u : order)
			if (!seen[u])
			{
				comp.clear(); ++cc;
				visit(u, radj, comp);
				for (int v : comp)
					id[v] = cc;
			}

		for (int u = 0; u < n; ++u)
			if (id[u] == id[neg(u)]) return false;
			else value[u] = id[u] > id[neg(u)];

		return true;
	}
};


int main()
{
	#ifdef DGC
		freopen("a.txt", "r", stdin);
		//freopen("b.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(0), cin.tie(0);

	freopen("binary.in", "r", stdin);
	freopen("binary.out", "w", stdout);

	int n;
	cin >> n;
	vector<string> a(n);
	for (auto &i : a) cin >> i;

	node *root = new_node();

	auto insert = [&](string s, int id)
	{
		node *cur = root;
		for (auto j : s)
		{
			assert(j != '?');
			if (!cur->ch[j-'0'])
				cur->ch[j-'0'] = new_node();
			cur = cur->ch[j-'0'];
		}
		cur->cid.push_back(id);
	};

	vector<pair<int, int>> edges;

	auto neg = [&](int u)
	{
		return -u-1;
	};

	auto add = [&](int u, int v)
	{
		//debug("add", u, v)
		edges.push_back({ u, v });
	};

	auto ca = a;
	for (auto &i : a)
	{
		int id = &i-&a[0];
		int p = -1;
		for (auto &j : i)
			if (j == '?')
			{
				p = &j-&i[0];
				break;
			}

		if (p != -1)
		{
			i[p] = '0';
			insert(i, 2*id);
			i[p] = '1';
			insert(i, 2*id+1);
			i[p] = '0';            // ???
			ca[id][p] = '1';

			add(2*id, neg(2*id+1));
			add(neg(2*id+1), 2*id);
			continue;
		}

		insert(i, 2*id);
		add(neg(2*id), 2*id);
	}

	int sz = nodes.size();
	int id = 2*n + sz;
	for (auto &p : nodes)
	{
		if (!p->cid.empty())
		{
			auto &v = p->cid;

			if (v.size() > 1)
			{
				int k = v.size();
				vector<int> pre(k), suf(k);
				for (int i = 0; i < k-1; ++i)
				{
					pre[i] = id++;
					add(pre[i], neg(v[k]));
					if (i > 0) add(pre[i], pre[i-1]);
				}

				for (int i = k-1; i > 0; --i)
				{
					suf[i] = id++;
					add(suf[i], neg(v[k]));
					if (i+1 < k) add(suf[i], suf[i+1]);
				}

				for (int i = 0; i < k; ++i)
				{
					if (i > 0) add(v[k], pre[i-1]);
					if (i+1 < k) add(v[k], suf[i+1]);
				}
			}

			for (auto x : v)
				for (int j = 0; j < 2; ++j)
					if (p->ch[j])
						add(x, 2*n + p->ch[j]->id);

			for (auto x : v)
				add(2*n + p->id, neg(x));
		}

		for (int j = 0; j < 2; ++j)
			if (p->ch[j])
				add(2*n + p->id, 2*n + p->ch[j]->id);
	}

	auto decode = [&](int u)
	{
		if (u >= 0) return u;
		return 2*id + u;
	};

	sat2 sat(id);
	for (auto i : edges)
		sat.implication(decode(i.F), decode(i.S));

	if (!sat.solve())
	{
		cout << "NO\n";
		return 0;
	}

	cout << "YES\n";
	for (int i = 1; i < 2*n; i += 2)
		if (sat.value[i])
		{
			int p = i/2;
			a[p] = ca[p];
		}

	for (auto &i : a)
		cout << i << "\n";

	/*fflush(stdout);

	for (auto i : nodes)
		i->print();*/

	return 0;
}