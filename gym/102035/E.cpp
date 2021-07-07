#include <bits/stdc++.h>

using namespace std;

#define rep(I,A,B) for(int I = A;I < B;++I)
#define sz(x) ((x).size())
#define MAX 205
#define endl '\n'

typedef long long ll;
typedef pair<int,int> pii;


int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    int c = 0, mis = false;
    rep(i, 0, n)
    {
    	int x; cin >> x;
    	if(x > m) c++;
    	mis |= (x == m);
    }
    if(k == 0 && c == 0 && mis) cout << "YES\n";
    else if(k == 0) cout << "NO\n";
    else if(c > k) cout << "NO\n";
    else cout << "YES\n";

}