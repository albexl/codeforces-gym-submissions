#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
 
typedef long long ll;
typedef pair<int, int> pii;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> f(10);
    for(auto &c : s)
    	f[c - 'a']++;

    int s1 = 1e9, s2 = -1;
    for(int i = 0; i < 5; i++)
    	s1 = min(s1, f[i]), s2 = max(s2, f[i]);

    cout << s1 << " " << s2 << endl;

    return 0;
}