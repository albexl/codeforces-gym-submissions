#include<bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

#define endl '\n'
#define MAX

typedef long long ll;
typedef pair<int,int> pii;
//typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;

int a, b, c, x;
double A, B, C, X;

double sqr(double x){
	return x * x;
}

double dist(double xo, double yo, double xi, double yi){
	return sqrt(sqr(xo - xi) + sqr(yo - yi));
}

double f(double yc, double xo, double yo, double xi, double yi){
	return dist(xo, yo, B + C, yc) + dist(xi, yi, B + C, yc);
}

double solve(double xo, double yo, double xi, double yi){
	double lo = yo;
	double hi = yi;
	
	for(int i = 0; i < 150; i++){
		double third = (hi - lo) / 3.0;
		double p1 = lo + third;
		double p2 = hi - third;
		
		if(f(p1, xo, yo, xi, yi) < f(p2, xo, yo, xi, yi))
			hi = p2;
		else
			lo = p1;
	}
	
	return f(lo, xo, yo, xi, yi);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	cout << setprecision(12) << fixed;
	
	int t;
	cin >> t;
	while(t--){
		
		cin >> a >> b >> c >> x;
		A = 1.0 * a, B = 1.0 * b, C = 1.0 * c, X = 1.0 * x;
		
		double ans = solve(0, -A, B, 0);
		
		double d = dist(0, -A, B, 0);
		
		d = d * (X / 100.0);
		double m = A / B;
		double n = -A;
		
		ans += d;

		double lo = 0.0, hi = B;
		for(int i = 0; i < 100; i++){
			double xo = (lo + hi) / 2.0;
			double yo = xo * m + n;
			double dd = dist(xo, yo, 0, -A);
			if(dd > d)
				hi = xo;
			else
				lo = xo;
		}
		
		ans += solve(lo, lo * m + n, B, 0);
		
		cout << ans << endl;
	}

	return 0;
}