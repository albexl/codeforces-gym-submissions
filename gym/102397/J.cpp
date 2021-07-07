#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
 
typedef long long ll;
typedef pair<int, int> pii;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, x, a;
    cin >> n >> x >> a;

    int ans = 1;

    int cur = a;
    for(int i = 0; i < n; i++){
    	if(cur - x >= 0){
    		cur -= x;
    	}
    	else{
    		cur = a;
    		ans++;
    		cur -= x;
    	}
    }

    cout << ans << endl;

    return 0;
}