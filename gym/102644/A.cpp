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

typedef vector<double> vec;
typedef vector<vec> mat;

double add(double a, double b){
	return a + b;
}

double mul(double a, double b){
	return a * b;
}

mat eye(int n)
{
	mat I(n, vec(n));
	for (int i = 0; i < n; ++i)
		I[i][i] = 1.0;
	return I;
}

mat mul(mat A, mat B)
{
	int l = A.size(), m = B.size(), n = B[0].size();
	mat C(l, vec(n));
	for (int i = 0; i < l; ++i)
		for (int k = 0; k < m; ++k)
			for (int j = 0; j < n; ++j)
				C[i][j] = add(C[i][j], mul(A[i][k], B[k][j]));
	return C;
}

mat pow(mat A, int b)
{
	mat X = eye(A.size());
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
	//freopen("output.txt", "w", stdout);

	int n;
	double p;

	cin >> n >> p;

	cout << setprecision(10) << fixed;

	mat A = {{1.0 - p, p}, 
			 {p, 1.0 - p}};

	mat B = {{1.0},
			 {0.0}};

	A = pow(A, n);
	A = mul(A, B);

	cout << A[0][0] << endl;

	return 0;
}