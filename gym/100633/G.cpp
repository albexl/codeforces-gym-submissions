#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<vector<int>> graph;

const ll oo = 0x3f3f3f3f3f3f3f3f;
const ll B = 1e6;
const ll B1 = 12 * B * B;

struct hour{

	ll h, m, s;

	bool operator<(hour t) const{

		if(h != t.h)
			return h < t.h;
		if(m != t.m)
			return m < t.m;
		return s < t.s;
	}

	bool operator==(hour t) const{

		return h == t.h && m == t.m && s == t.s;
	}

};

void print(hour a){
	cout << a.h << " " << a.m << " " << a.s << endl;
}

ll conv(hour a){
	return a.h * B * B + a.m * B + a.s;
}

hour inv(ll x){
	hour ans;
	ans.h = x / (B * B);
	ans.m = (x % (B * B)) / B;
	ans.s = x % B;
	return ans;
}


hour dif(hour a, hour b){

	ll x1 = conv(a), x2 = conv(b);
	if(x1 <= x2)
		return inv(x2 - x1);
	else
		return inv(B1 - x1 + x2);
}

hour sum(hour a, hour b){

	hour ans;

	ans.h = a.h + b.h;
	ans.m = a.m + b.m;
	ans.s = a.s + b.s;

	ans.m += ans.s / B;
	ans.s %= B;
	ans.h += ans.m / B;
	ans.m %= B;

	return ans;
}

hour mnus(hour a, hour b){
	hour ans;

//	cout << "voy a restar" << endl;
//	print(a);
//	print(b);

	if(a.s >= b.s)
		ans.s = a.s - b.s;
	else{

		if(a.m > 0){
			a.m--;
			a.s += B;
			ans.s = a.s - b.s;
		}
		else{
			a.h--;
			a.m += B;
			a.m--;
			a.s += B;
			ans.s = a.s - b.s;
		}

	}

//	print(a);

//	a.m += a.s / B;
//	a.s %= B;
//	a.h += a.m / B;
//	a.m %= B;

//	print(a);

	if(a.m >= b.m){
		ans.m = a.m - b.m;
	}
	else{
		a.h--;
		a.m += B;
		ans.m = a.m - b.m;
	}

//	print(a);

//	a.h += a.m / B;
//	a.m %= B;

//	print(a);

	ans.h = a.h - b.h;

	ans.m += ans.s / B;
	ans.s %= B;
	ans.h += ans.m / B;
	ans.m %= B;


	return ans;
}

hour mul(hour a, ll b){
	hour ans;

	ans.s = a.s * b;
	ans.m = ans.s / B;
	ans.s %= B;

	ans.m += a.m * b;
	ans.h = ans.m / B;
	ans.m %= B;

	ans.h += a.h * b;

	return ans;
}



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<hour> a(n);

	vector<pair<hour, ll>> b;

	for(int i = 0; i < n; i++)
		cin >> a[i].h >> a[i].m >> a[i].s;

	sort(a.begin(), a.end());

	hour best = {0, 0, 0};

	for(int i = 0; i < n; i++)
		best = sum(best, dif(a[i], a[0]));



	hour cur = {best.h, best.m, best.s};

//	cout << best.h << " " << best.m << " " << best.s << endl;

	ll cnt = 0;

	for(int i = 1; i < n; i++){
		if(a[i] == a[i - 1]){
			cnt++;
			continue;
		}
		b.push_back({a[i - 1], cnt + 1});
		cnt = 0;
	}

	b.push_back({a[n - 1], cnt + 1});

	for(int i = 1; i < (int)b.size(); i++){

//		cout << b[i].second << endl;

		hour d = dif(b[i - 1].first, b[i].first);
		hour dmul = mul(d, 1LL * n - b[i].second);

		hour d2 = dif(b[i].first, b[i - 1].first);
		hour dmul2 = mul(d2, b[i].second);


//		print(d);
//		print(dmul);
//		print(d2);
//		print(dmul2);
//
//		print(cur);

		cur = sum(cur, dmul);

//		print(cur);

		cur = mnus(cur, dmul2);

//		print(cur);



		if(cur < best)
			best = cur;

	}

	print(best);

	return 0;
}