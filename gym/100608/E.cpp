#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	freopen("elegant.in", "r", stdin);
	freopen("elegant.out", "w", stdout);

	const int maxn = 1000;
	vector<bool> isp(maxn, true);
	vector<int> pr;
	for(int i = 2; i < maxn; ++i)
		if(isp[i])
		{
			for(int j = i * i; j < maxn; j += i)
				isp[j] = false;
			pr.push_back(i);
		}

	int n;
	cin >> n;

	vector<vector<ll>> ans(n, vector<ll>(n));

	for(int it = 0; it < n; ++it)
		for(int i = 0, j = it; i < n; ++i, j = (j + 1) % n)
			ans[i][j] = pr[it];

	for(int it = n; it < n + n; ++it)
		for(int i = 0, j = it % n; i < n; ++i, j = (j + n - 1) % n)
			ans[i][j] *= pr[it];

	if(n % 2 == 0)
	{
		for(int it = n + n; it < n + n + n / 2; it++){
			for(int i = 0, j = it % (n / 2); i < n; ++i, j = (j + 1) % n){
				if(i < n / 2){
					ans[i][j % (n / 2)] *= pr[it];
//					cout << i << " " << j % (n / 2) << " " << it << endl;
				}
				else{
					ans[i][n / 2 + (j + 1) % (n / 2)] *= pr[it];
//					cout << i << " " << n / 2 + (j + 1) % (n / 2) << " " << it << endl;
				}


			}
		}

		for(int it = n + n + n / 2; it < n + n + n; it++){
			for(int i = 0, j = it % (n / 2); i < n; ++i, j = (j + 1) % n){
				if(i >= n / 2){
//					cout << i << " " << (j + 1) % (n / 2) << " " << it << endl;
					ans[i][(j + 1) % (n / 2)] *= pr[it];
				}
				else{
//					cout << i << " " << j % (n / 2) + n / 2 << " " << it << endl;
					ans[i][j % (n / 2) + n / 2] *= pr[it];

				}
			}
		}
	}

	for(auto &v : ans)
		for(int i = 0; i < (int)v.size(); ++i)
			cout << v[i] << " \n"[i + 1 == (int)v.size()];



//	for(int xx = 3; xx <= 30; xx++)
//	{
//		int n = xx;

//	int n = 8;
//
//	vector<vector<int>> ans(n, vector<int>(n));
//
//	vector<vector<vector<int>>> am(100, vector<vector<int>>(100, vector<int>(100)));
//
//	for(int it = 0; it < n; ++it)
//		for(int i = 0, j = it; i < n; ++i, j = (j + 1) % n)
//			ans[i][j] = pr[it], ++am[it][i][j];
//
//	for(int it = n; it < n + n; ++it)
//		for(int i = 0, j = it % n; i < n; ++i, j = (j + n - 1) % n)
//			ans[i][j] *= pr[it], ++am[it][i][j];
//
//	for(auto &v : ans)
//		for(int i = 0; i < (int)v.size(); ++i)
//			cout << v[i] << " \n"[i + 1 == (int)v.size()];

//	set<int> S;
//	for(int i = 0; i < n; ++i)
//		for(int j = 0; j < n; ++j)
//		{
//			if(S.find(ans[i][j]) != S.end())
//			{
//				cout << "repeated " << n << endl;
//				return 0;
//			}
//			S.insert(ans[i][j]);
//		}
////
//	for(int it = 0; it < n + n; ++it)
//	{
//		int ss = -1;
//		for(int i = 0, s = 0; i < n; ++i, s = 0)
//		{
//			for(int j = 0; j < n; ++j)
//				s += am[it][i][j];
//
//			if(ss == -1)
//				ss = s;
//
//			if(ss != s)
//			{
//				cout << n << " " << it << " " << i << " " << s << " " << ss << endl;
//				cout << endl;
//				for(auto &v : ans)
//					for(int i = 0; i < (int)v.size(); ++i)
//						cout << v[i] << " \n"[i + 1 == (int)v.size()];
//
//
//				cout << endl << "bad 1" << endl;
//				return 0;
//			}
//		}
//
//		for(int j = 0, s = 0; j < n; ++j, s = 0)
//		{
//			for(int i = 0; i < n; ++i)
//				s += am[it][i][j];
//
//			if(ss == -1)
//				ss = s;
//
//			if(ss != s)
//			{
//				cout << "bad 2" << endl;
//				return 0;
//			}
//		}
//	}
//	}

	return 0;
}