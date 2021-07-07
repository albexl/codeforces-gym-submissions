#include <bits/stdc++.h>

using namespace std;

#ifdef DGC
#include "debug.h"
#else
#define debug(...) 9715;
#endif
typedef long long ll;
typedef long double ld;
typedef complex<double> point;
#define F first
#define S second

// contrary clock side direction
pair<double, double> rotacion(double x, double y, double ang)
{
	ang = (acos(-1.0) * ang) / 180.0;
	return { x * cos(ang) - y * sin(ang), x * sin(ang) + y * cos(ang) };
}

typedef vector<ld> vec;
typedef vector<vec> mat;

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
	mat C(l, vec(n));
	for (int i = 0; i < l; ++i)
		for (int k = 0; k < m; ++k)
			for (int j = 0; j < n; ++j)
				C[i][j] += A[i][k] * B[k][j];
	return C;
}

mat pow(mat A, ll b)
{
	mat X = eye(A.size());
	for (; b > 0; b >>= 1)
	{
		if (b & 1) X = mul(X, A);
		A = mul(A, A);
	}
	return X;
}

int main()
{
	#ifdef DGC
		//freopen("a.in", "r", stdin);
		//freopen("b.out", "w", stdout);
	#endif

	ios_base::sync_with_stdio(0), cin.tie(0);

	int t;
	cin >> t;
	cout.precision(10);
	cout << fixed;
	while (t--)
	{
		ld ang, l; int n;
		cin >> ang >> l >> n;

		ang = (acosl(-1.0) * ang) / 180.0;
		mat A = { { cosl(ang), -sinl(ang), l }, { sinl(ang), cosl(ang), 0 }, { 0, 0, 1 } };

		A = pow(A, n);
		cout << A[0][2] << " " << A[1][2] << "\n";
	}

	return 0;
}