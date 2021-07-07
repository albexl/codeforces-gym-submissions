#include <bits/stdc++.h>

using namespace std;

#ifdef Adrian
#include "debug.h"
#else
#define debug(...)
#endif
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef complex<ll> point;
#define F first
#define S second
#define ii pair<int,int>


typedef pair<int,int> pii;

const int maxn = 1e6 + 5;
const int maxp = 1e7 + 5;

int a[maxn], pi[maxn], sieve[maxp], n;
int f[maxp], last[maxn];
bool root[maxn];

int solve(int p, int k){



	if(p > n)
		return 0;



	if(root[p] && last[p] < k){



		int adj = solve(p + 1, p + 1);

//		 cout << p << " :" << endl;
//		 cout << "root" << endl;
//		 cout << adj << endl;

		pi[adj] = p;
		return p;
	}
	else{



		if(last[p] < k){
			int adj = solve(p + 1, k);
			pi[p] = p + 1;

//			 cout << p << " :" << endl;
//			 cout << "no root" << endl;
//			 cout << adj << endl;
			return adj;
		}
		else{
			cout << "impossible" << endl;
			exit(0);
		}
	}
}

int main()
{
	#ifdef Adrian
		freopen("a.txt", "r", stdin);
		//freopen("b.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(0), cin.tie(0);

	for(int i = 2; i < maxp; i++){
		if(sieve[i] == 0){
			for(int j = i; j < maxp; j += i)
				sieve[j] = i;
		}
	}

	set<int> s;

	cin >> n;
	
	for(int i = 1; i <= n; i++)
		cin >> a[i];

	for(int i=1; i<=n; i++)
	{
		int x = a[i];

		while(x > 1){

			// cerr << i << " " << x << endl;

			int p = sieve[x];
			last[i]=max(last[i],f[p]);

			f[p]=i;

			while(x % p == 0){
				// cerr << x << " " << p << endl;
				x /= p;
			}

		}
	}


	for(int i = n; i >= 1; i--){
		root[i] = true;
		int x = a[i];

		while(x > 1){

			// cerr << i << " " << x << endl;

			int p = sieve[x];
			if(s.find(p) != s.end())
				root[i] = false;

			s.insert(p);
			while(x % p == 0){
				// cerr << x << " " << p << endl;
				x /= p;
			}

		}
	}

	// for(int i = 1; i <= n; i++)
	// 	cout << root[i] << " \n"[i == n];
	// cout << endl;

	// cerr << "here" << endl;
	solve(1,1);

	for(int i = 1; i <= n; i++)
		cout << pi[i] << " \n"[i == n];


	return 0;
}