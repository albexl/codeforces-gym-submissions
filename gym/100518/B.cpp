#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<ll, ll> pii;

const int maxn = 5000 + 5;
const double oo = 1e15;

int n;
ll a[maxn], b[maxn], c[maxn], d[maxn];
double dp1[maxn], dp2[maxn];

double cost(int l, int r){

	ll sumA = a[r] - a[l - 1];
	ll sumB = b[r] - b[l - 1];
	ll sumC = c[r] - c[l - 1];
	ll sumD = d[r] - d[l - 1];

	if(sumA > 0 && sumC > 0){
		double k = 1.0 * (sumC + sumD - sumB) / (sumA + sumC);
		if(k > 1)
			k = 1.0;
		if(k < 0)
			k = 0.0;
		return min(k * sumA + sumB, (1.0 - k) * sumC + sumD);
	}
	else return 1.0 * min(sumC + sumD, sumA + sumB);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	freopen("braess.in", "r", stdin);
	freopen("braess.out", "w", stdout);

	cout << setprecision(10) << fixed;

	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i] >> b[i] >> c[i] >> d[i];

	for(int i = 1; i <= n; i++){
		a[i] += a[i - 1];
		b[i] += b[i - 1];
		c[i] += c[i - 1];
		d[i] += d[i - 1];
	}

	double s1 = cost(1, n);
	double s2 = 0.0;

	for(int i = 1; i <= n; i++)
		s2 += cost(i, i);

	double s3 = oo, s4 = 0;

	for(int i = 1; i < maxn; i++)
		dp1[i] = oo;

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= i; j++){
			dp1[i] = min(dp1[i], dp1[j - 1] + cost(j, i));
			dp2[i] = max(dp2[i], dp2[j - 1] + cost(j, i));
		}
	}

	s3 = dp1[n], s4 = dp2[n];

	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;


	return 0;
}