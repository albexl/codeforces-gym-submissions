#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);


	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
		
		vector<ll> c(n + 2), am(n + 2);
		
		for(int i = 1; i <= n; i++)
			cin >> c[i];
		
		for(int i = 0; i < m; i++){
			int x;
			ll y;
			cin >> x >> y;
			am[x] += y;
		}
		
		for(int i = 1; i <= n; i++){
			if(c[i] < am[i]){
				ll rem = am[i] - c[i];
				am[i + 1] += rem;
				am[i] = c[i];
			}
		}
		
		cout << am[n + 1] << endl;
		for(int i = 1; i <= n; i++)
			cout << am[i] << " \n"[i == n];
		
		
	}

	return 0;
}