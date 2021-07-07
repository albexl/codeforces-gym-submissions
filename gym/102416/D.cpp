#include <bits/stdc++.h>
 
using namespace std;

#define endl '\n'
 
typedef long long ll;
typedef pair<int, int> pii;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;

int gauss(vector<vector<double>> a, vector<double> &ans)
{
	int n = (int) a.size();
	int m = (int) a[0].size() - 1;

	vector<int> where(m, -1);
	for (int col = 0, row = 0; col < m && row < n; ++col)
	{
		int sel = row;
		for (int i = row; i < n; ++i)
			if (abs(a[i][col]) > abs(a[sel][col]))
				sel = i;
		if (abs(a[sel][col]) < eps)
			continue;
		for (int i = col; i <= m; ++i)
			swap(a[sel][i], a[row][i]);
		where[col] = row;

		for (int i = 0; i < n; ++i)
			if (i != row)
			{
				double c = a[i][col] / a[row][col];
				for (int j = col; j <= m; ++j)
					a[i][j] -= a[row][j] * c;
			}

		++row;
	}

	ans.assign(m, 0);

	for (int i = 0; i < m; ++i)
		if (where[i] != -1)
			ans[i] = a[where[i]][m] / a[where[i]][i];

	for (int i = 0; i < n; ++i)
	{
		double sum = 0;
		for (int j = 0; j < m; ++j)
			sum += ans[j] * a[i][j];
		if (abs(sum - a[i][m]) > eps)
			return 0;
	}

	for (int i = 0; i < m; ++i)
		if (where[i] == -1)
			return oo;
	return 1;
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	//freopen("points.in", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cout << setprecision(10) << fixed;

	int k, n;

	cin >> k >> n;

	vector<vector<double>> dp(n + 1, vector<double>(n + 2));
	vector<double> ans(n + 1);

	dp[n][n] = 1.0;

	dp[0][0] = 1.0;
	dp[0][1] = (-1.0 / k) / (1.0 - (k - 1.0) / k);
	dp[0][n + 1] = 1.0 / (1.0 - (k - 1.0) / k);

	for(int i = 1; i < n; i++){
		dp[i][i] = 1.0;
		dp[i][n + 1] = 1.0;
		dp[i][i + 1] = -1.0 / k;
		dp[i][0] = -(k - 1.0) / k;
	}

	gauss(dp, ans);

	cout << ans[0] << endl;
	
	return 0;	
}