#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <random>
#include <chrono>

using namespace std;
using namespace __gnu_pbds;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;
//typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;

//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct frac{
	
	ll x, y;
	
	frac(ll _x, ll _y){
		ll g = __gcd(abs(_x), abs(_y));
		x = _x / g;
		y = _y / g;
	}
	
};

frac sum(frac a, frac b){
	
	ll g = __gcd(abs(a.y), abs(b.y));
	
	ll m = a.y * b.y / g;
	
	ll sum = m / a.y * a.x + m / b.y * b.x;
	
	g = __gcd(abs(sum), abs(m));
	
	return frac(sum / g, m / g);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	string line;
	while(cin >> line){

		stack<ll> sign;
				
		frac cur(0, 1);
		sign.push(+1);
		
		for(int i = 0; i < line.size(); i++){
			
			
			if(line[i] == '('){
				ll last = sign.top();
				sign.push(last);
				continue;
			}
				

		
			if(line[i] == ')'){
				sign.pop();
				continue;
			}
			
			if( (line[i] == '-' || line[i] == '+') && line[i + 1] == '('){
				
				ll mul = 1;
				if(line[i] == '-')
					mul = -1;
				
				ll last = sign.top();
				sign.push(mul * last);
				i++;
			
				continue;
			}
			
			ll mul = 1;
			
			if(line[i] == '-')
				mul = -1;
			
			ll last = sign.top();
			mul = last * mul;
			
			if(line[i] == '+' || line[i] == '-')
				i++;
			
			ll x = 0;
			while(isdigit(line[i])){
				x = x * 10 + (line[i] - '0');
				i++;
			}
			
			i++;
			
			ll y = 0;
			while(i < line.size() && isdigit(line[i])){
				y = y * 10 + (line[i] - '0');
				i++;
			}
			
			//cout << x << " " << y << endl;
							
			frac n_frac(mul * x, y);
			
			cur = sum(cur, n_frac);
			
			i--;

		}
		
		cout << cur.x << "/" << cur.y << endl;
		
	}

	return 0;
}