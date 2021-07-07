#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;

ll mul(ll x, ll y, ll M){
	return (x * y) % M;
}

ll add(ll x, ll y, ll M){
	x += y;
	if(x > M)
		x -= M;
	return x;
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

const ll mod = 998244353;


int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("figure.in", "r", stdin);
	freopen("figure.out", "w", stdout);
	
	mat A = {{1, 1, 1, 0}, {1, 2, 2, 0}, {0, 0, 1, 1}, {0, 1, 2, 1}};
	
	ll n;
	while(cin >> n && n){
		mat B = pow(A, n, mod);
		cout << B[0][0] << endl;
	}

	return 0;
}