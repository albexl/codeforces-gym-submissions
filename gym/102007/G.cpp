#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 1e5 + 5;

string s;

int n, a[maxn], b[maxn], c[maxn];

int get_a(int lo, int hi){
	if(a[n - 1] == 0)
		return 0;
	if(lo <= hi){
		int cnt = a[hi];
		if(lo)
			cnt -= a[lo - 1];
		return cnt;
	}

	int c1 = a[n - 1];
	if(lo)
		c1 -= a[lo - 1];

	c1 += a[hi];
	return c1;
}

int get_b(int lo, int hi){
	if(b[n - 1] == 0)
		return 0;
	if(lo <= hi){
		int cnt = b[hi];
		if(lo)
			cnt -= b[lo - 1];
		return cnt;
	}

	int c1 = b[n - 1];
	if(lo)
		c1 -= b[lo - 1];

	c1 += b[hi];
	return c1;
}

int get_c(int lo, int hi){
	if(c[n - 1] == 0)
		return 0;
	if(lo <= hi){
		int cnt = c[hi];
		if(lo)
			cnt -= c[lo - 1];
		return cnt;
	}

	int c1 = c[n - 1];
	if(lo)
		c1 -= c[lo - 1];

	c1 += c[hi];
	return c1;
}

int solve(vector<char> v){
	int A = a[n - 1];
	int B = b[n - 1];
	int C = c[n - 1];

//	cout << v[0] << " " << v[1] << " " << v[2] << endl;
//	cout << endl;
//
	int ans = 1e9;

	for(int i = 0; i < n; i++){

		int la = i, ha = (i + A - 1 + n) % n;

		int lb = v[1] == 'B' ? (ha + 1) % n : (ha + C + 1) % n;
		int hb = (lb + B - 1 + n) % n;

		int lc = v[1] == 'C' ? (ha + 1) % n : (ha + B + 1) % n;
		int hc = (lc + C - 1 + n) % n;

//		cout << i << " :" << endl;
//		cout << la << " " << ha << endl;
//		cout << lb << " " << hb << endl;
//		cout << lc << " " << hc << endl;
//		cout << endl;
////
		int a1 = get_a(la, ha), b1 = get_b(la, ha), c1 = get_c(la, ha);

		int a2 = get_a(lb, hb), b2 = get_b(lb, hb), c2 = get_c(lb, hb);

		int a3 = get_a(lc, hc), b3 = get_b(lc, hc), c3 = get_c(lc, hc);

		if(A == 0)
			a1 = 0, b1 = 0, c1 = 0;
//
		if(B == 0)
			a2 = 0, b2 = 0, c2 = 0;

		if(C == 0)
			a3 = 0, b3 = 0, c3 = 0;

//		cout << a1 << " " << b1 << " " << c1 << endl;
//		cout << a2 << " " << b2 << " " << c2 << endl;
//		cout << a3 << " " << b3 << " " << c3 << endl;


//		int cost = 2 * (min(b1, a2) + min(c1, a3) + min(c2, b3));
//
//		int nA = A - a1 - min(b1, a2) - min(c1, a3);
//		cost += 4 * nA;

//		cout << b1 + c1 + a2 + c2 + a3 + b3 << endl;
//		cout << endl;

		ans = min(ans, b1 + c1 + a2 + c2 + a3 + b3);
	}

	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);


	cin >> n >> s;

	for(int i = 0; i < n; i++){
		if(i)
			a[i] += a[i - 1], b[i] += b[i - 1], c[i] += c[i - 1];
		if(s[i] == 'A')
			a[i]++;
		if(s[i] == 'B')
			b[i]++;
		if(s[i] == 'C')
			c[i]++;
	}

	int ans = min(solve({'A', 'B', 'C'}), solve({'A', 'C', 'B'}));

	cout << ans << endl;

	return 0;
}