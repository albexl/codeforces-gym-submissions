#include <bits/stdc++.h>
#define ii pair<int,int>
using namespace std;
const int MAXN=1e4+5;
vector<int>graph[MAXN];
int in1[MAXN],in2[MAXN];
int further[MAXN];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(".in","r",stdin);
    int n,k;
    cin>>n>>k;
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        if(x==0)continue;
        --x;
        graph[i].push_back(x);
        ++in1[x];
        ++in2[x];
    }
    queue<int>q;
    vector<int>TS;
    for(int i=0; i<n; i++)
        if(!in1[i])
            q.push(i);
    while(!q.empty())
    {
        int cur=q.front();
        q.pop();
        TS.push_back(cur);
        for(int v:graph[cur])
        {
            --in1[v];
            if(!in1[v])
                q.push(v);
        }
    }
    for(int i=TS.size()-1; i>=0; i--)
    {
        int cur=TS[i];
        for(int v:graph[cur])
            further[cur]=max(further[cur],further[v]+1);
    }
    priority_queue<ii>pq;
    for(int i=0; i<n; i++)
        if(!in2[i])
            pq.push(ii(further[i],i));
    int ans=0;
    while(!pq.empty())
    {
        ++ans;
        vector<int>temp;
        for(int i=0; i<k && !pq.empty(); i++)
        {
            int cur=pq.top().second;
            pq.pop();
            for(int v:graph[cur])
                temp.push_back(v);
        }
        for(int v:temp)
        {
            --in2[v];
            if(!in2[v])
                pq.push(ii(further[v],v));
        }
    }
    cout<<ans;
    return 0;
}