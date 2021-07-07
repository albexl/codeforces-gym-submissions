#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 1e5 + 5;

int pi[maxn], sz[maxn];
map<string, int> mp;

void init(int n){
	for(int i = 0; i < n; i++){
		sz[pi[i] = i] = 1;
		string s;
		cin >> s;
		mp[s] = i;
	}
}

int set_of(int x){
	return x == pi[x] ? x : set_of(pi[x]);
}

bool merge(int x, int y){

	x = set_of(x);
	y = set_of(y);

	if(x == y)
		return false;

	if(sz[x] > sz[y])
		swap(x, y);

	pi[x] = y;
	sz[y] += sz[x];

	return true;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	init(n);

	while(m--){
		int t;
		string a, b;
		cin >> t >> a >> b;
		int x = mp[a];
		int y = mp[b];

		if(t == 1)
			merge(x, y);
		else{
			x = set_of(x);
			y = set_of(y);

			cout << (x == y ? "yes" : "no") << endl;
		}

	}


	return 0;
}