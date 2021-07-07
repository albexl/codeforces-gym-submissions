#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <random>
#include <chrono>
 
using namespace std;
using namespace __gnu_pbds;
 
#define endl '\n'
 
typedef long long ll;
typedef pair<ll, ll> pii;
typedef tree<int, null_type,less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
template<typename T>
static T randint(T lo, T hi){
	return uniform_int_distribution<T>(lo, hi)(rng);
}

typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;

ll add(ll a, ll b, ll M)
{
	a += b;
	if (a >= M) a -= M;
	return a;
}

ll sub(ll a, ll b, ll M)
{
	if (a < b) a += M;
	return a - b;
}

ll mul(ll a, ll b, ll M)
{
	return a * b % M;
}

ll pow(ll a, ll b, ll M)
{
	ll x = 1;
	for (; b > 0; b >>= 1)
	{
		if (b & 1) x = mul(x, a, M);
		a = mul(a, a, M);
	}
	return x;
}

// Modular Matrix
mat eye(int n)
{
	mat I(n, vec(n));
	for (int i = 0; i < n; ++i)
		I[i][i] = 1;
	return I;
}

mat zeros(int n)
{
	return mat(n, vec(n));
}

mat mul(mat &A, mat &B, ll M)
{
	int l = A.size(), m = B.size(), n = B[0].size();
	mat C(l, vec(n));
	for (int i = 0; i < l; ++i)
		for (int k = 0; k < m; ++k)
			for (int j = 0; j < n; ++j)
				C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % M;
	return C;
}

mat pow(mat &A, ll b, ll M)
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
	// freopen("output.txt", "w", stdout);

	const ll mod = 1e9 + 7;

	int n, m, q;
	cin >> n >> m >> q;

	mat A(n, vec(n));
	while(m--){
		int a, b;
		cin >> a >> b;
		a--, b--;
		A[a][b]++;
	}

	vector<mat> pows(30);
	pows[0] = A;
	for(int i = 1; i < 30; i++)
		pows[i] = mul(pows[i - 1], pows[i - 1], mod);


	while(q--){
		int a, b;
		ll k;
		cin >> a >> b >> k;
		a--, b--;

		mat B(n, vec(1));
		B[b][0] = 1;

		for(int i = 0; i < 30; i++)
			if(k & (1ll << i))
				B = mul(pows[i], B, mod);

		cout << B[a][0] << endl;
	}

	return 0;
}