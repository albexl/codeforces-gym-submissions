#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <random>
#include <chrono>
 
using namespace std;
using namespace __gnu_pbds;
 
#define endl '\n'
 
typedef long long ll;
typedef pair<int, int> pii;
typedef tree<int, null_type,less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
template<typename T>
static T randint(T lo, T hi){
	return uniform_int_distribution<T>(lo, hi)(rng);
}


typedef vector<ll> vec;
typedef vector<vec> mat;

ll add(ll a, ll b, ll M){
	return (a + b) % M;
}

ll mul(ll a, ll b, ll M){
	return a * b % M;
}

mat eye(int n)
{
	mat I(n, vec(n));
	for (int i = 0; i < n; ++i)
		I[i][i] = 1;
	return I;
}

mat mul(mat A, mat B, ll M)
{
	int l = A.size(), m = B.size(), n = B[0].size();
	mat C(l, vec(n));
	for (int i = 0; i < l; ++i)
		for (int k = 0; k < m; ++k)
			for (int j = 0; j < n; ++j)
				C[i][j] = add(C[i][j], mul(A[i][k], B[k][j], M), M);
	return C;
}

mat pow(mat A, ll b, ll M)
{
	mat X = eye(A.size());
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

	const ll mod = 1e9 + 7;

	int n, m, k;
	cin >> n >> m >> k;

	vector<vector<ll>> A(n, vector<ll>(n));

	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		a--, b--;
		A[a][b]++;
	}

	A = pow(A, k, mod);

	ll ans = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			ans = (ans + A[i][j]) % mod;

	cout << ans << endl;
 
	return 0;
}