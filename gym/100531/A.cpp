#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
 
typedef long long ll;
typedef pair<int, int> pii;

 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("alarm.in", "r", stdin);
    freopen("alarm.out", "w", stdout);

    vector<int> v = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

    int n;
    cin >> n;

    for(int x = 0; x < 24; x++){
    	for(int y = 0; y < 60; y++){

    		int nx = x;
    		int b = nx % 10;
    		nx /= 10;
    		int a = nx % 10;

    		int ny = y;
    		int d = ny % 10;
    		ny /= 10;
    		int c = ny % 10;

    		if(v[a] + v[b] + v[c] + v[d] == n){
    			cout << a << b << ":" << c << d << endl;
    			return 0;
    		}

    	}
    }

    cout << "Impossible" << endl;

    return 0;
}