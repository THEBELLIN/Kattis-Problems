#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
#define MAX 20000

ll n,m,q,s, d[MAX];
vector<pll> gr[MAX];
bool used[MAX];

int main()
{
    while(cin>>n>>m>>q>>s)
    {
        if(n==0)
            break;
        for(int i=0; i<n; i++)
        {
            gr[i].clear();
            used[i]=0;
            d[i]=-1;
        }
        for(int i=0; i<m; i++)
        {
            ll a, b, w;
            cin>>a>>b>>w;
            gr[a].push_back({b,w});
        }

        priority_queue<pll, vector<pll>, greater<pll>> pq;

        pq.push({0, s});
        d[s]=0;

        while(!pq.empty())
        {
            ll n= pq.top().second;
            pq.pop();

            if(used[n])
                continue;
            used[n]=1;
            for(pll x:gr[n])
            {
                ll m=x.first, val=x.second;
                if(!used[m] && (d[m]==-1 || d[m] >d[n]+val))
                {
                    d[m]=d[n]+val;
                    pq.push({d[m], m});

                }
            }
        }
        for(int i=0; i<q; i++)
        {
            ll x;
            cin>>x;
            if(d[x]==-1)
              cout<<"Impossible"<<endl;
            else
                cout<<d[x]<<endl;
        }
    }
}