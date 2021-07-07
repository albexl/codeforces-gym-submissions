#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
 
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<bool> vec;
typedef vector<vec> mat;

mat eye(int n)
{
	mat I(n, vec(n));
	for (int i = 0; i < n; ++i)
		I[i][i] = true;
	return I;
}

mat mul(mat A, mat B)
{
	int l = A.size(), m = B.size(), n = B[0].size();
	mat C(l, vec(n));
	for (int i = 0; i < l; ++i)
		for (int k = 0; k < m; ++k)
			for (int j = 0; j < n; ++j)
				C[i][j] = C[i][j] | (A[i][k] & B[k][j]);
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
 
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){

    	int n, m;
    	ll k;
    	cin >> n >> m >> k;

    	mat A(n, vec(n, false));

    	for(int i = 0; i < m; i++){
    		int a, b;
    		cin >> a >> b;
    		A[a][b] = A[b][a] = true;
    	}

    	A = pow(A, k);
    	int ans = 0;
    	for(int i = 0; i < n; i++)
    		ans += A[i][i];

    	cout << ans << endl;
    }
 

    return 0;
}