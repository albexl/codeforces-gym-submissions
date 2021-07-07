    //VS
    #include<iostream>
    #include<cstdio>
    #include<vector>
    #include<algorithm>
    #include<iomanip>
    #include<cstring>
    #include<string>
    #include<cmath>
    #include<stack>
    #include<queue>
    #include <cstdlib>
    #define PB push_back
    #define remove erase
    #define endl '\n'
    #define FOR for(int I = 0;I < N;++I)
    #define MAX
     
    using namespace std;
     
    typedef long long i64;
    typedef pair<int, int> pii;
     
    bool IsPalindrome(char *a)
    {
    	int hi = strlen(a) - 1;
    	int lo = 0;
    	while(lo <= hi){
    		if(a[lo++] != a[hi--])
    			return false;
    	}
    	return true;
    }
     
    bool IsValid(char *a)
    {
    	int l = strlen(a);
    	for (int i = 0; i < l; i++)
    	{
    		if (a[i] != 'A' && a[i] != 'H' && a[i]!= 'I' && a[i]!='M' && a[i]!='O' && a[i]!='T' && a[i]!='U' && a[i]!='V' && a[i]!='W' && a[i]!='X' && a[i]!='Y')
    		{
    			return false;
    		}
    	}
    	return true;
    }
    int main()
    {
    	ios_base::sync_with_stdio(0);
    	cin.tie();
    	int n;
    	char a[1005];
    	scanf("%d", &n);
    	while (n--)
    	{
    		
    		scanf("%s", a);
    		if (IsPalindrome(a) && IsValid(a))
    		{
    			printf("yes\n");
    		}
    		else
    		{
    			printf("no\n");
    		}
    	}
    	//system("pause");
    }