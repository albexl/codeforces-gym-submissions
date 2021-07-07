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
    #define double ld
     
    double area(double x, double y, double z)
    {
        if (x + y <= z || x + z <= y || y + z <= x) return 1e18;
        double p = x + y + z;
        p /= 2.0;
        return p * (p - x) * (p - y) * (p - z);
    }
     
    double f(double a, double b)
    {
        return sqrtl(a*a + b*b);
    }
     
    int main()
    {
    	#ifdef Adrian
    		freopen("a.txt", "r", stdin);
    		//freopen("b.txt", "w", stdout);
    	#endif
    	ios_base::sync_with_stdio(0), cin.tie(0);
     
    	cout.precision(15);
    	cout << fixed;
     
    	int t;
    	cin>>t;
    	while(t--)
    	{
    		int n;
    		cin>>n;
    		vector<double> v(n);
     
    		for(int i=0; i<n; i++)
    			cin>>v[i];
     
    		sort(v.begin(), v.end());
     
    		double ans = 1e18;
    		for(int i=0; i< n-1; i++)
    			for(int j = i+1; j<n; j++)
    			{
    				int r = lower_bound(v.begin(), v.end(), v[i]+ v[j]) - v.begin() - 1;
    				int l = upper_bound(v.begin(), v.end(), v[j] - v[i]) - v.begin();
     
    				for(int mid = max(l,r-7); mid<=r; mid++)
    				    if (mid >= 0 && mid < n && mid != i && mid != j)
            			{
            				double eval1 = area(v[i], v[j], v[mid]);
            				ans = min(ans, eval1);
            			}
            			
            		
     
    				for(int mid = l; mid<=min(r,l+7); mid++)
    				    if (mid >= 0 && mid < n && mid != i && mid != j)
            			{
            				double eval1 = area(v[i], v[j], v[mid]);
            				ans = min(ans, eval1);
            			}
    			}
    			
    		if(ans < 1e15)
    			cout<<sqrtl(ans)<<'\n';
    		else
    			cout<<-1<<'\n';
    	}
     
    	return 0;
    }