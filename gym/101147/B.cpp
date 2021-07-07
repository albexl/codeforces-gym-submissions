 
#include<bits/stdc++.h>
 
using namespace std;
 
typedef vector<int> vi;
 
typedef long long ll;
 
//#define pii pair<int , ll>
 
#define node pair <int , ll>
 
#define complex <double> P;
#define MAXV 100000 + 5
#define oo 1000000000000000ll;
 
 
 
int t;
 
double DP[105][105];
 
double H[105];
double W[105];
double D[105];
int K[105];
int a[105];
 
bool cmp(int a,int b)
{
	return D[a] < D[b];
}
 
int main()
{
	freopen("street.in","r",stdin);
	
	scanf("%d",&t);
	while(t--)
	{
		int n;
		long long L,U;
		scanf("%d%lld%lld",&n,&L,&U);
 
 
		for(int i = 0 ; i <= n + 1; i++)
		{
			for(int j = i + 1 ; j <= n + 1; j++)
			{
				DP[i][j] = 10000000000.00;
			}
		}
 
 
		for(int i = 1 ; i <= n ; i++)
		{
			a[i] = i;
 
			scanf("%lf%lf%lf%d",&H[i],&W[i],&D[i],&K[i]);
		}
		
		for(int i = 1 ; i <= n ; i++)
		{
			DP[0][i] = DP[i][0] = D[i];
			
			DP[i][n + 1] = DP[n + 1][i] = L - (D[i] + H[i]);
		}
 
		sort(a + 1,a + (n + 1),cmp);
 
		for(int i = 1 ; i <= n ; i++)
		{
			for(int j = i + 1 ; j <= n ; j++)
			{
				if(K[i] == K[j])
					DP[i][j] = DP[j][i] = abs(D[i] + H[i] - D[j]);
				else if(D[i] + H[i] >= D[j] && D[i] + H[i] <= D[j] + H[j])
					DP[i][j] = DP[j][i] = U - W[i] - W[j];
				else
				{
					double d1 = U - W[i] - W[j];
 
					double d2 = abs(D[i] - D[j]);
 
					double S1 = sqrt(d1*d1 + d2*d2);
 
					double d3 = abs(D[i] - (D[j] + H[j]));
 
					S1 = min(S1,sqrt(d1*d1 + d3*d3));
 
					double d4 = abs(D[j] - (D[i] + H[i]));
 
					S1 = min(S1,sqrt(d1*d1 + d4*d4));
 
					double d5 = abs((D[i] + H[i])-(D[j] + H[j]));
 
					S1 = min(S1,sqrt(d1*d1 + d5*d5));
 
					DP[i][j] = DP[j][i] = S1;
				}
			}
		}
 
 
		for(int k = 0 ; k <= n + 1; k++)
		{
			for(int i = 0; i <= n + 1; i++)
			{
				for(int j = 0 ;j <= n + 1; j++)
				{
					DP[i][j] = min(DP[i][j], DP[i][k] + DP[k][j]);
				}
			}
		}
 
		printf("%.6lf\n",DP[0][n + 1]);
	}
	
}