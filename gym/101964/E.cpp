#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
 
 
typedef long long ll;
typedef pair<ll, ll> pii;
 


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);


	int n, m, l;
	cin >> n >> m >> l;

	vector<pii> p(n);

	for(int i = 0; i < n; i++){
		int x, y;
		cin >> x >> y;
		p[i] = {x, y};
	}

	vector<pair<pii, int>> events;

	for(int i = 0; i < m; i++){
		int x;
		cin >> x;
		events.push_back({{x, 10}, i});
	}

	for(int i = 0; i < n; i++){
		int x = p[i].first;
		int y = p[i].second;

		if(y > l)
			continue;

		int lo = x + y - l;
		int hi = x + l - y;

		events.push_back({{lo, +1}, i});
		events.push_back({{hi + 1, -1}, i});

	}

	sort(events.begin(), events.end());

	vector<int> ans(m);
	int cnt = 0;

	for(auto &e : events){

		int x = e.first.first;
		int t = e.first.second;
		int idx = e.second;

		if(t == 10)
			ans[idx] = cnt;
		else
			cnt += t;
	}

	for(int i = 0; i < m; i++)
		cout << ans[i] << endl;

	return 0;
}

/*

8 4 4
7 2
3 3
4 5
5 1
2 2
1 4
8 4
9 4
6 1 4 9

*/