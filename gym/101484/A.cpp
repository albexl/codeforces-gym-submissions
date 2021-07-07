#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<ll, ll> pii;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, x;
    cin >> n >> x;

    vector<int> v(n);

    for(int i = 0; i < n; i++){
    	cin >> v[i];
    	if(v[i] == x){
    		cout << 1 << endl;
    		return 0;
    	}
    }

    sort(v.begin(), v.end());
    if(x >= v[0] && x <= v[n - 1])
    	cout << 2 << endl;
    else
    	cout << -1 << endl;

    return 0;
}