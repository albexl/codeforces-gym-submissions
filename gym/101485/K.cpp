#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 1000 + 5;

bool A[maxn][maxn], f[maxn];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int r, s, m, d, n;

	cin >> r >> s >> m >> d >> n;

	vector<ll> b(r + 1);

	for(int i = 1; i <= r; i++)
		cin >> b[i];

	ll ans = 0;

	vector<vector<int>> S(s + 1), M(m + 1), D(d + 1);

	for(int i = 1; i <= s + m + d; i++){
		int k;
		cin >> k;

		for(int j = 0; j < k; j++){
			int x;
			cin >> x;

			if(i <= s)
				S[i].push_back(x);
			else if(i > s && i <= s + m)
				M[i - s].push_back(x);
			else if(i > s + m)
				D[i - s - m].push_back(x);
		}
	}

	for(int i = 0; i < n; i++){
		int x, y;
		cin >> x >> y;
		A[x][y] = A[y][x] = true;
	}

	for(int i = 1; i <= s; i++){
		for(int j = 1; j <= m; j++){
			for(int k = 1; k <= d; k++){
				if(A[i][j + s] || A[i][k + s + m] || A[j + s][k + s + m])
					continue;

				vector<int> used;

				//get in
				for(auto &val : S[i]){
					if(!f[val]){
						f[val] = true;
						used.push_back(val);
					}
				}

				for(auto &val : M[j]){
					if(!f[val]){
						f[val] = true;
						used.push_back(val);
					}
				}

				for(auto &val : D[k]){
					if(!f[val]){
						f[val] = true;
						used.push_back(val);
					}
				}


				//get out
				for(auto &val : S[i])
					f[val] = false;

				for(auto &val : M[j])
					f[val] = false;

				for(auto &val : D[k])
					f[val] = false;


				ll add = 1;
				for(auto &val : used){
					if( (long double)add * b[val] > 1e18){
						cout << "too many" << endl;
						return 0;
					}

					add *= b[val];
				}

				ans += add;

				if(ans > 1e18){
					cout << "too many" << endl;
					return 0;
				}

			}
		}
	}

	cout << ans << endl;

	return 0;	
}