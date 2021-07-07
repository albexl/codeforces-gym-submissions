#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;

bool good(vector<int> &v, vector<int> &w)
{
	multiset<int> S1;
	for(auto &j : v)
		for(auto &k : v)
			if(j != k)
				S1.insert(j + k);

	multiset<int> S2;
	for(auto &j : w)
		for(auto &k : w)
			if(j != k)
				S2.insert(j + k);

	while(!S1.empty() && !S2.empty() && *S1.begin() == *S2.begin())
		S1.erase(S1.begin()), S2.erase(S2.begin());
	return S1.empty() && S2.empty();
}

pair<vector<int>, vector<int>> solve(int n)
{
	if(n == 2)
		return {{1, 4}, {2, 3}};

	auto x = solve(n >> 1);
	x.first.resize(n);
	x.second.resize(n);
	int h = n / 2;
	for(int i = 0; i < h; ++i)
	{
		x.first[h + i] = x.second[i] + n;
		x.second[h + i] = x.first[i] + n;
	}
	return x;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	freopen("analogous.in", "r", stdin);
	freopen("analogous.out", "w", stdout);

	int n;
	while(cin >> n && n)
	{
		if((n & -n) == n)
		{
			auto x = solve(n);
			cout << "Yes" << endl;
			for(int i = 0; i < n; ++i)
				cout << x.first[i] << " \n"[i + 1 == n];
			for(int i = 0; i < n; ++i)
				cout << x.second[i] << " \n"[i + 1 == n];
//			cout << good(x.first, x.second) << endl;
		}
		else
			cout << "No" << endl;
	}

//	if(n == 2)
//			{
//				cout << "Yes" << endl;
//				cout << "1 4" << endl;
//				cout << "2 3" << endl;
//			}
//			else if(n == 4)
//			{
//				cout << "Yes" << endl;
//				cout << "2 3 5 8" << endl;
//				cout << "1 4 6 7" << endl;
//			}
//			else if(n == 8)
//			{
//				cout << "Yes" << endl;
//				cout << "1 4 6 7 10 11 13 16" << endl;
//				cout << "2 3 5 8 9 12 14 15" << endl;
//			}
//
//	vector<int> v = {1, 4, 6, 7, 10, 11, 13, 16, 18, 19, 21, 24, 25, 28, 30, 31};
//	vector<int> w = {2, 3, 5, 8, 9, 12, 14, 15, 17, 20, 22, 23, 26, 27, 29, 32};
//
//	cout << good(v, w);

//	int n;
//	while(cin >> n && n)
//	{
//		if(n == 3)
//			cout << "No" << endl;
//		else if(n == 5)
//		{
//			cout << "Yes" << endl;
//			cout << "1 4 5 6 7" << endl;
//			cout << "2 3 4 5 8" << endl;
//		}
//		else if(n == 6)
//		{
//			cout << "Yes" << endl;
//			cout << "1 2 3 5 6 7" << endl;
//			cout << "1 2 3 4 5 8" << endl;
//		}
//		else if(n == 7)
//		{
//			cout << "Yes" << endl;
//			cout << "1 2 3 4 6 7 8" << endl;
//			cout << "1 2 3 5 6 7 8" << endl;
//		}
//		else
//		{
//	for(int n = 4; n <= 1000; ++n){
//			vector<int> v(n), w(n);
//
//			for(int i = 0, it = 0; i + 1 < n; i += 2)
//			{
//				if(i + 2 == n && n > 4)
//					swap(v, w);
//				v[i] = ++it, w[i] = ++it, w[i + 1] = ++it, v[i + 1] = ++it;
//				if(i == 0)
//					swap(v, w);
//			}
//			if(n & 1)
//				swap(v[n - 2], w[n - 2]), v[n - 1] = n + n, w[n - 1] = n + n - 1;
//
////			cout << "Yes" << endl;
////			for(int j = 0; j < n; ++j)
////				cout << v[j] << " \n"[j + 1 == n];
////			for(int j = 0; j < n; ++j)
////				cout << w[j] << " \n"[j + 1 == n];
////		cout << good(v, w) << endl;
////		if(!good(v, w))
////		{
////			cout << n << endl;
////			for(int j = 0; j < n; ++j)
////				cout << v[j] << " \n"[j + 1 == n];
////			for(int j = 0; j < n; ++j)
////					cout << w[j] << " \n"[j + 1 == n];
////			return 0;
////		}
//			if(good(v, w))
//			{
//				cout << n << endl;
//				cout << "Yes" << endl;
//				for(int j = 0; j < n; ++j)
//					cout << v[j] << " ";
//				cout << endl;
//				for(int j = 0; j < n; ++j)
//					cout << w[j] << " ";
//				cout << endl;
//			}
//		}
//	}

//	#define BIT(x) (1 << (x))
//
//	int n = 8, m = 12;
//	int sz = BIT(m);
//
//	vector<vector<int>> V;
//	for(int i = 0; i < sz; ++i)
//		if(__builtin_popcount(i) == n)
//		{
//			vector<int> v;
//			for(int j = 0; j < m; ++j)
//			{
//				if(BIT(j) & i)
//					v.push_back(j + 1);
//			}
//			V.push_back(v);
//		}
//
//	cout << V.size() << endl;
//
//	for(int i = 0; i < (int)V.size(); ++i)
//		for(int j = i + 1; j < (int)V.size(); ++j)
//			if(good(V[i], V[j]))
//			{
//				cout << "Yes " << V[i].size() << endl;
//				for(int k = 0; k < n; ++k)
//					cout << V[j][k] << " \n"[k + 1 == n];
//				for(int k = 0; k < n; ++k)
//					cout << V[i][k] << " \n"[k + 1 == n];
//				return 0;
//			}
//
//	cout << "No" << endl;

//	#define BIT(x) (1 << (x))
////
//	int n = 8;
//	int sz = BIT(n + n);
//
//	for(int i = 0; i < sz; ++i)
//		if(__builtin_popcount(i) == n)
//		{
//			vector<int> v, w;
//			for(int j = 0; j < n + n; ++j)
//			{
//				if(BIT(j) & i)
//					v.push_back(j + 1);
//				else w.push_back(j + 1);
//			}
//
//			if(good(v, w))
//			{
//				for(int j = 0; j < n; ++j)
//					cout << v[j] << " ";
//				cout << endl;
//				for(int j = 0; j < n; ++j)
//					cout << w[j] << " ";
//				cout << endl;
//				cout << endl;
//			}
//		}

	return 0;
}