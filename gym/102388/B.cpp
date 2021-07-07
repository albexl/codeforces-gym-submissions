#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
 
typedef long long ll;
typedef pair<int, int> pii;
 
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
    	ll a, b, c, d;
    	cin >> a >> b >> c >> d;
    	ll g = __gcd(abs(a - c), abs(b - d));
    	cout << g + 1 << endl;
    }
 

    return 0;
}