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

const ll oo = 4e18;

mat eye(int n)
{
	mat I(n, vec(n));
	for (int i = 0; i < n; ++i)
		I[i][i] = 1;
	return I;
}

mat mul(mat &A, mat &B)
{
	int l = A.size(), m = B.size(), n = B[0].size();
	mat C(l, vec(n, oo));
	for (int i = 0; i < l; ++i)
		for (int k = 0; k < m; ++k)
			for (int j = 0; j < n; ++j)
				C[i][j] = min(C[i][j], A[i][k] + B[k][j]);
	return C;
}

mat pow(mat &A, int b)
{
	mat X = mat(A.size(), vec(A.size(), oo));
	for(int i = 0; i < A.size(); i++)
		X[i][i] = 0;
	for (; b > 0; b >>= 1)
	{
		if (b & 1) X = mul(X, A);
		A = mul(A, A);
	}
	return X;
}


 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	//freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	int n, m, k;
	cin >> n >> m >> k;

	mat A(n, vec(n, oo));

	for(int i = 0, a, b; i < m; i++){
		ll c;
		cin >> a >> b >> c;
		a--, b--;
		A[a][b] = c;
	}

	A = pow(A, k);

	ll ans = oo;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			ans = min(ans, A[i][j]);

	if(ans >= 2e18)
		cout << "IMPOSSIBLE" << endl;
	else
		cout << ans << endl;

	return 0;
}

/*

3 4 1
1 2 12
2 3 -5
3 1 20
2 1 -1

*/