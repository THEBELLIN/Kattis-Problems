#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
vector<pii> g[10010];
int distances[10000];
bool used[10010];

int main()
{
    while(1)
    {
        memset(used, 0, 10000);
        int n, m, a, k;
        cin>>n>>m>>a>>k;
        if(n==0 && m==0 && a==0 && k==0)
            break;
        for(int i=1; i<=n; i++)
        {
            distances[i]=9999999;
            used[i]=0;
        }
        while(m--)
        {
            int t1, t2, d;
            cin>>t1>>t2>>d;
            g[t1].push_back({t2,d});
            g[t2].push_back({t1,d});
        }
        while(a--)
        {
            int al;
            cin>>al;
            queue<pii> q; //index, dist
            q.push({al, 0});
            used[al]=1;
            distances[al]=0;
            while(!q.empty())
            {
                int x=q.front().first;
                for(pii xx:g[x])
                {
                    if(!used[xx.first])
                    {
                        distances[xx.first]=min(distances[x]+xx.second,distances[xx.first]);
                        if(distances[xx.first]==distances[x]+xx.second) //TODO
                            q.push({xx.first,distances[xx.first]});
                        used[xx.first]=1;
                    }
                }
                q.pop();
            }
            memset(used, 0, 10000);
            int co=0;
            for(int i=1; i<=n; i++)
            {
                if(distances[i]>=k)
                    co++;
            }
            cout<<co<<endl;
        }
        cout<<endl;
    }
}