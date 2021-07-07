#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<ll, ll> pii;


const int maxn = 300 + 5;

int n;
vector<int> g[maxn];
bool visited[maxn];
int cnt = 0;

bool ok = false;


vector<int> path, comb;

void print(){
	for(int i = 0; i < (int)path.size(); i++)
		cout << path[i] + 1 << " ";
	for(int i = 0; i < (int)comb.size(); i++)
		cout << comb[i] + 1 << " \n"[i + 1 == (int)comb.size()];
}

void dfs(int u, int lvl){

//	cout << u << " " << lvl << endl;

	path.push_back(u);

	visited[u] = true;
	cnt++;

	if(cnt == n){
		ok = true;
		print();
		return;
	}


	if(lvl){
		for(auto &v : g[u]){
			for(auto &y : g[u]){
				if(v != y && !visited[v] && !visited[y]){

					visited[y] = true;
					cnt++;
					comb.push_back(y);
					dfs(v, lvl + 1);
					comb.pop_back();
					visited[y] = false;
					cnt--;
					if(ok)
						return;
				}
			}
		}
	}
	else{

		for(auto &v : g[u]){
			if(!visited[v])
				dfs(v, lvl + 1);
			if(ok)
				return;
		}
	}


	cnt--;
	visited[u] = false;
	path.pop_back();
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	freopen("embedding.in", "r", stdin);
	freopen("embedding.out", "w", stdout);


	while(cin >> n && n){


		path.clear();
		comb.clear();
		cnt = 0;
		for(int i = 0; i < maxn; i++){
			g[i].clear();
			visited[i] = false;
		}
		ok = false;


		set<pii> bad;

		n *= 2;

		for(int i = 0; i < n / 2; i++){
			bad.insert({i, (i + 1) % n});
			bad.insert({(i + 1) % n, i});
			path.push_back(i);
		}

		path.push_back(n / 2);


		for(int i = 1; i < n / 2; i++){
			bad.insert({i, n - i});
			bad.insert({n - i, i});
			comb.push_back(n - i);
		}

		print();
		path.clear();
		comb.clear();

		for(int i = n / 2; i < n; i++){
			bad.insert({i, (i + 1) % n});
			bad.insert({(i + 1) % n, i});
			path.push_back(i);
		}

		path.push_back(0);

		reverse(path.begin(), path.end());

		for(int i = n - 1; i > n / 2 + 1; i--){
			bad.insert({i, n - i + 1});
			bad.insert({n - i + 1, i});
			comb.push_back(n - i + 1);

	//		cout << i << " " << n - i + 1 << endl;

		}

		bad.insert({n / 2 + 1, 1});
		bad.insert({1, n / 2 + 1});

		comb.push_back(1);

		print();

		path.clear();
		comb.clear();

	//	cout << "bad" << endl;
	//	for(auto &e : bad)
	//		cout << e.first << " " << e.second << endl;
	//
	//	cout << (bad.size() == (4 * (n - 1))) << endl;
	//	cout << "edges" << endl;

		for(int i = 0; i < n; i++)
			for(int j = i + 1; j < n; j++)
				if(bad.find(pii(i, j)) == bad.end()){
					g[i].push_back(j);
					g[j].push_back(i);

	//				cout << i << " " << j << endl;

				}



		dfs(1, 0);
	}

	return 0;
}