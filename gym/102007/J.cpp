#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;

const double eps = 1e-9;

double heron(double a, double b, double c){
	double s = (a + b + c) / 2.0;
	return sqrt(s * (s - a) * (s - b) * (s - c));
}

double f(double x, double a, double b, double c, double d){

	return heron(a, b, x) + heron(c, d, x);
}

double solve(double a, double b, double c, double d){
	double lo = 0.0, hi = a + b + c + d + 100000;

	lo = max(lo, a - b);
	lo = max(lo, b - a);

	lo = max(lo, c - d);
	lo = max(lo, d - c);

	hi = min(hi, a + b);
	hi = min(hi, c + d);

	if(lo > hi + eps)
		return 0.0;

	for(int i = 0; i < 300; i++){
		double third = (hi - lo) / 3.0;
		double p1 = lo + third;
		double p2 = hi - third;

		if(f(p1, a, b, c, d) > f(p2, a, b, c, d))
			hi = p2;
		else
			lo = p1;
	}
	return f(lo, a, b, c, d);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cout << setprecision(10) << fixed;

	vector<int> d(4);
	for(int i = 0; i < 4; i++)
		cin >> d[i];

	sort(d.begin(), d.end());

	double ans = 0.0;

	do{

		ans = max(ans, solve(d[0], d[1], d[2], d[3]));

	}while(next_permutation(d.begin(), d.end()));

	cout << ans << endl;

	return 0;
}