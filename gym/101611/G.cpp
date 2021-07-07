#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;

#define int ll
 
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);


	int n, m;
	cin >> n >> m;

	vector<int> R(n), C(m);

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			int x, y;
			cin >> x >> y;

			R[i] += y;
			C[j] += x;
		}
	}

	bool ok = true;
	for(int i = 0; i < n; i++)
		if(R[i])
			ok = false;
	for(int i = 0; i < m; i++)
		if(C[i])
			ok = false;

	cout << (ok ? "Yes" : "No") << endl;


	return 0;
}