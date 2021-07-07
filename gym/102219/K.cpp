#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef pair<int, int> pii;
typedef long long ll;


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);



	int t;
	cin >> t;

	int cases = 1;

	while(t--){

		int n;
		cin >> n;
		vector<ll> v(n);

		for(int i = 0; i < n; i++)
			cin >> v[i];

		sort(v.begin(), v.end());

		int ans = 0;

		ll cur = 0;
		for(auto &val : v){
			if(cur + val <= 2 * val){
				ans++;
				cur += val;
			}
		}

		cout << "Case #" << cases++ << ": " << ans << endl;


	}
	

	return 0;
}