#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
 
typedef long long ll;
typedef pair<int, int> pii;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;

    if(n & 1)
    	cout << "Bashar" << endl;
    else
    	cout << "Mahmoud" << endl;

    return 0;
}