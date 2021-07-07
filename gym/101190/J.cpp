#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'


typedef long long ll;
typedef pair<int, int> pii;

 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	freopen("jenga.in", "r", stdin);
	freopen("jenga.out", "w", stdout);

	int n, w, h, m;
	cin >> n >> w >> h >> m;

	vector<ll> x(h + 100), y(h + 100), cnt(h + 100), sumx(h + 100), sumy(h + 100), sum_cnt(h + 100);

	vector<ll> left(h + 100), right(h + 100);

	vector<vector<bool>> F(h + 100, vector<bool>(n + 100, true));


	for(int i = 1; i <= h; i++){
		left[i] = 1;
		right[i] = 1ll * n;
		cnt[i] = 1ll * n;

		x[i] = 1ll * n * n;
		y[i] = 1ll * n * n;

	}

	for(int i = h; i >= 1; i--){
		sumx[i] = sumx[i + 1] + x[i];
		sumy[i] = sumy[i + 1] + y[i];
		sum_cnt[i] = sum_cnt[i + 1] + cnt[i];
	}
	
	for(int k = 0; k < m; k++){
		int r, c;
		cin >> r >> c;

		if(r & 1)
			x[r] -= 2ll * c - 1ll, y[r] -= 1ll * n;
		else{

			if(r < 0 || r >= (int)y.size() || r >= (int)x.size()){
				cout << r << " " << (int)y.size() << " " << (int)x.size() << endl;
				return 0;
			}

			assert(r >= 0 && r < (int)y.size());
			assert(r >= 0 && r < (int)x.size());
			y[r] -= 2ll * c - 1ll, x[r] -= 1ll * n;
		}

		F[r][c] = false;
		cnt[r]--;

		ll ll = 0, rr = 0;

		for(int j = 1; j <= n; j++){
			if(F[r][j])
				rr = 1ll * j;
			if(F[r][j] && ll == 0)
				ll = 1ll * j;
		}

		left[r] = ll;
		right[r] = rr;


		for(int j = r; j >= 1; j--){

			sumx[j] = sumx[j + 1] + x[j];
			sumy[j] = sumy[j + 1] + y[j];
			sum_cnt[j] = sum_cnt[j + 1] + cnt[j];

			if(sum_cnt[j + 1] && (sumx[j + 1] <= (left[j] - 1) * 2 * sum_cnt[j + 1] || !cnt[j]) ){
				cout << "yes" << endl;
				cout << k + 1 << endl;
				return 0;
			}

			if(sum_cnt[j + 1] && (sumy[j + 1] >= right[j] * 2 * sum_cnt[j + 1] || !cnt[j]) ){
				cout << "yes" << endl;
				cout << k + 1 << endl;
				return 0;
			}
		}

	}

	cout << "no" << endl;

	return 0;
}