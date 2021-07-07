    #include <bits/stdc++.h>

    using namespace std;

    #ifdef Adrian
    #include "debug.h"
    #else
    #define debug(...)
    #endif
    typedef long long ll;
    typedef long double ld;
    typedef complex<double> point;
    #define F first
    #define S second
    #define ii pair<int,int>

    int main()
    {
    	//#ifdef Adrian
    		freopen("grave.in", "r", stdin);
    		freopen("grave.out", "w", stdout);
    	//#endif

    	ios_base::sync_with_stdio(0), cin.tie(0);

    	int x1,y1,x2,y2,x3,y3,x4,y4;
    	cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;

    	int w,h;
    	cin>>w>>h;

    	if(((x2 - x4 >= w || x3 - x1 >= w) && y2 - y1 >=h) || ((y2 - y4 >= h || y3 - y1 >= h) && x2-x1 >= w))
    		cout<<"Yes";
    	else
    		cout<<"No";

    	return 0;
    }