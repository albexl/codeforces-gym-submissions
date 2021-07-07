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

const ll mod = 1e9 + 7;

ll get(ll x){
	if(x == 0)return 1LL;
	ll ans = 0;
	while(x > 0){
		x /= 10LL;
		ans++;
	}
	return ans;
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		ll m, n;
		cin >> m >> n;
		
		if(m == 1){
			cout << n << endl;
			continue;
		}
			
		
		ll len = get(n);
		ll t = 1;
		
		for(ll i = 0; i < len; i++)
			t = t * 10LL % mod;
		
		mat A = {{t, 1}, {0, 1}};
		mat B = {{n}, {n}};
		A = pow(A, m - 1, mod);
		
		mat C = mul(A, B, mod);
		
		ll ans = C[0][0];
		cout << ans << endl;
		
	}

	return 0;
}