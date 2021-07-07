#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
 
typedef long long ll;
typedef pair<int, int> pii;
 
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int n;
    ll k;
    cin >> n >> k;
 
    vector<ll> a(n + 1), b(n + 1);
    ll s1 = 0, s2 = 0;
 
    map<ll, ll> mp1, mp2;
 
    for(int i = 1; i <= n; i++){
    	cin >> a[i];
    	s1 += mp1[k - a[i]];
    	mp1[a[i]]++;
    }
 
    for(int i = 1; i <= n; i++){
    	cin >> b[i];
    	s2 += mp2[k - b[i]];
    	mp2[b[i]]++;
    }
 
    if(s1 == s2)
    	cout << "DRAW" << endl;
    else if(s1 < s2)
    	cout << "BASHAR" << endl;
    else
    	cout << "MAHMOUD" << endl;
 
 
    return 0;
}