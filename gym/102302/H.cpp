#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define MAX

typedef long long ll;
typedef pair<ll, int> pii;
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;


const ll mod = 1e9 + 7;

ll add(ll x, ll y, ll M){
	return (x + y) % M;
}

ll mul(ll x, ll y, ll M){
	return (x * y) % M;
}

vector<vector<ll>> eye(int n)
{
	vector<vector<ll>> I(n, vector<ll>(n));
	for (int i = 0; i < n; ++i)
		I[i][i] = 1;
	return I;
}

vector<vector<ll>> mul(vector<vector<ll>> A, vector<vector<ll>> B, ll M)
{
	int l = A.size(), m = B.size(), n = B[0].size();
	vector<vector<ll>> C(l, vector<ll>(n));
	for (int i = 0; i < l; ++i)
		for (int k = 0; k < m; ++k)
			for (int j = 0; j < n; ++j)
				C[i][j] = add(C[i][j], mul(A[i][k], B[k][j], M), M);
	return C;
}

vector<vector<ll>> pow(vector<vector<ll>> A, ll b, ll M)
{
	vector<vector<ll>> X = eye(A.size());
	for (; b > 0; b >>= 1)
	{
		if (b & 1) X = mul(X, A, M);
		A = mul(A, A, M);
	}
	return X;
}



int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);


	ll n;
	cin >> n;

	n -= 2;

	vector<pii> v;

	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++)
			v.push_back({i, j});

	vector<vector<ll>> A(9, vector<ll>(9));


	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			pii v1 = v[i];
			pii v2 = v[j];

			if(v1.second == v2.first && v1.first * v2.second <= v1.second * v1.second)
				A[i][j] = 1;
		}
	}

	auto B = pow(A, n, mod);

	ll ans = 0;

	for(int i = 0; i < 9; i++)
		for(int j = 0; j < 9; j++)
			ans = add(ans, B[i][j], mod);

	cout << ans << endl;

	return 0;
}