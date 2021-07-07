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
	
	int t;
	cin >> t;
	
	for(int cases = 1; cases <= t; cases++){
		cout << "Case " << cases << ": ";
		
		int n, m, c;
		cin >> n >> m >> c;
		
		vector<int> freq(m + 1);
		for(int i = 0, x; i < n; i++){
			cin >> x;
			freq[x]++;
		}
		
		vector<pii> v;
		for(int i = 1; i <= m; i++)
			if(freq[i])
				v.push_back({freq[i], i});
		
		sort(v.begin(), v.end());
		
		int N = v.size();
		
		vector<ll> sum(N);
		for(int i = N - 1; i >= 0; i--){
			sum[i] = 1ll * (v[i].second * v[i].second % c);
			if(i != N - 1)
				sum[i] += sum[i + 1];
		}
		
		ll ans = 0;
		int pos = 0;
		
		for(int h = 1; h <= n; h++){
			while(pos < v.size() && v[pos].first < h)
				pos++;
			
			if(pos == v.size())
				break;
			
			ans = max(ans, 1ll * h * sum[pos]);
		}
		
		cout << ans << endl;
	}

	return 0;
}