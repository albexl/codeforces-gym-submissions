#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'


typedef long long ll;
typedef pair<int, int> pii;


#define int ll

const int eps = 1e16;

ll sum(int l, int r){
	return 1ll * r * (r + 1) / 2ll - 1ll * l * (l - 1) / 2ll;
}
 
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ll t;
	int n, m;
	cin >> t >> n >> m;

	vector<int> a(m), b(m);
	for(int i = 0; i < m; i++)
		cin >> a[i] >> b[i];


	for(int i = 0; i + 1 < m; i++){

		if(abs(a[i] - a[i + 1]) < abs(b[i] - b[i + 1]) ){

			cout << "No" << endl;
			return 0;
		}
	}

	ll mn = 0;

	for(int i = 0; i + 1 < m; i++){

		int xo = a[i], yo = b[i], xi = a[i + 1], yi = b[i + 1];

		if(yo > yi){
			swap(xo, xi);
			swap(yo, yi);
		}



		mn -= 1ll * b[i + 1];
		
		// cout << mn << " resta 2" << endl;

		mn += sum(yo + 1, yi);

		mn = min(mn, t + eps);

		// cout << mn << " suma 0" << endl;

		if(mn > t){
			cout << "No" << endl;
			return 0;
		}

		xi -= yi - yo;
		yi = yo;


		int x_mid = (xo + xi) / 2;
		int y_mid = max(0ll, yi - abs(xo - x_mid));


		if(abs(xo - xi) % 2 == 0){

			mn -= 1ll * y_mid;
			// cout <<  mn << " resta 1" << endl;
		}

		mn += sum(y_mid, yo);

		mn = min(mn, t + eps);

		mn += sum(y_mid, yo);

		mn = min(mn, t + eps);



		// cout << "suma 6" << endl;

		if(mn > t){
			cout << "No" << endl;
			return 0;
		}


	}

	int xo = a[0], yo = b[0];
	int yi = max(0ll, yo - (xo - 1));

	// cout << mn << endl;

	mn += sum(yi, yo - 1);
	mn = min(mn, t + eps);

	// cout << mn << endl;

	if(mn > t){
		cout << "No" << endl;
		return 0;
	}

	xo = a[m - 1], yo = b[m - 1];
	yi = max(0ll, yo - (n - xo));

	mn += sum(yi, yo);

	mn = min(mn, t + eps);

	// cout << mn << endl;

	if(mn > t){
		cout << "No" << endl;
		return 0;
	}

	//////maximo

	ll mx = 0;

	for(int i = 0; i + 1 < m; i++){

		int xo = a[i], yo = b[i], xi = a[i + 1], yi = b[i + 1];

		if(yo > yi){
			swap(xo, xi);
			swap(yo, yi);
		}

		mx -= 1ll * b[i + 1];
		mx += sum(yo, yi - 1);


		if(mx >= t)
			break;

		xo += yi - yo;
		yo = yi;

		int x_mid = (xo + xi) / 2;
		int y_mid = yi + abs(xo - x_mid);

		if(abs(xo - xi) % 2 == 0)
			mx -= 1ll * y_mid;

		
		mx += sum(yo, y_mid);

		if(mx >= t)
			break;

		mx += sum(yo, y_mid);

		if(mx >= t)
			break;

	}

	if(mx < t){
		int xo = a[0], yo = b[0];
		int yi = yo + (xo - 1);

		mx += sum(yo + 1, yi);

		mx = min(mx, t + eps);
	}

	if(mx < t){
		xo = a[m - 1], yo = b[m - 1];
		yi = yo + (n - xo);

		mx += sum(yo, yi);

		mx = min(mx, t + eps);
	}

	// cout << mn << " " << mx << endl;
	

	if(t >= mn && t <= mx)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	return 0;
}