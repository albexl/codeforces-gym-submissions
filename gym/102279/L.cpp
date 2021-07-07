#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> node;

const ll oo = 0x3f3f3f3f3f3f3f3f;
const int maxn = 2e5 + 5;

int n, l, r, c, a[maxn], s, t;
vector<pii> g[maxn];
ll d[maxn];

void dijkstra(){
	for(int i = 0; i < maxn; i++)
		d[i] = oo;

	priority_queue<node, vector<node>, greater<node>> pq;
	d[s] = 0ll;
	pq.push({0ll, s});

	while(!pq.empty()){

		ll c = pq.top().first;
		int u = pq.top().second;
		pq.pop();

		if(d[u] != c)
			continue;

		for(auto &e : g[u]){
			int v = e.first;
			int w = e.second;

			if(d[v] > d[u] + 1ll * w){
				d[v] = d[u] + 1ll * w;
				pq.push({d[v], v});
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n >> l >> r >> c >> s >> t;

	s--, t--;

	vector<int> b(n);

	for(int i = 0; i < n; i++)
		cin >> a[i], b[i] = a[i];

	sort(b.begin(), b.end());
	b.resize(unique(b.begin(), b.end()) - b.begin());

	for(int i = 0; i < n; i++){
		if(i)
			g[i].push_back({i - 1, l});
		if(i != n - 1)
			g[i].push_back({i + 1, r});

		int pos = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
		int u = n + pos;

		g[i].push_back({u, c});
		g[u].push_back({i, 0});
	}

	dijkstra();

	cout << d[t] << endl;

	return 0;	
}