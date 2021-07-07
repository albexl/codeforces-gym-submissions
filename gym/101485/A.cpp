#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;



int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);


	int n, m;
	cin >> n >> m;

	vector<pii> v(n);

	for(int i = 0; i < n; i++)
		cin >> v[i].first >> v[i].second;

	sort(v.begin(), v.end());

	vector<pii> segs;

	multiset<int> s, d;

	int ans = 0;

	for(int i = 0; i < n; i++){
		while(!s.empty() && *s.begin() <= v[i].first){
			d.insert(*s.begin() + m);
			s.erase(s.begin());
		}

		while(!d.empty() && *d.begin() < v[i].first)
			d.erase(d.begin());

		if(!d.empty()){
			ans++;
			d.erase(d.begin());
		}

		s.insert(v[i].first + v[i].second);
	}

	cout << ans << endl;

	return 0;	
}