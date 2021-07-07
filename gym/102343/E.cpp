#include<bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define MAX
 
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii> tri;
 
bool is_prime(int x){
	if(x <= 1)
		return false;
	for(int i = 2; i * i <= x; i++)
		if(x % i == 0)
			return false;
	return true;
}
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 	
	int n, k;
	cin >> n >> k;

	vector<int> primes;

	for(int i = 1; i <= n; i++)
		if(is_prime(i))
			primes.push_back(i);

	int cnt = 0, x;


	for(x = 2; cnt < k; x++){
		if(is_prime(x))
			continue;

		// cout << x << " :" << cnt << endl; 

		bool ok = true;
		for(auto &p : primes)
			if(x % p == 0){
				ok = false;
				break;
			}

		if(ok){
			cnt++;
		}
	}


	cout << x - 1 << endl;


	return 0;
}