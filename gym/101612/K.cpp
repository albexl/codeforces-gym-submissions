#include <bits/stdc++.h>

using namespace std;

#ifdef DGC
#include "debug.h"
#else
#define debug(...)
#endif
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
typedef complex<ll> point;
#define F first
#define S second



signed main()
{

	//#ifdef DGC
		freopen("kotlin.in", "r", stdin);
		freopen("kotlin.out", "w", stdout);
//	#endif

	ios_base::sync_with_stdio(0), cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;

	vector<vector<char>> a(n + 1, vector<char>(m + 1, '.'));

	for(int i = 1; i <= (n + 1) / 2; i++){
		for(int j = 1; j <= (m + 1) / 2; j++){

			if(i * j == k){

//				cout << i << " " << j << endl;

				i--, j--;

				for(int l = 2; i > 0; l += 2, i--){
					for(int s = 1; s <= m; s++){
						a[l][s] = '#';
					}
				}

				for(int l = 2; j > 0; l += 2, j--){
					for(int s = 1; s <= n; s++){
						a[s][l] = '#';
					}
				}

				for(int l = 1; l <= n; l++){
					for(int s = 1; s <= m; s++)
						cout << a[l][s];
					cout << endl;
				}


				return 0;
			}
		}
	}

	cout << "Impossible" << endl;


	return 0;
}