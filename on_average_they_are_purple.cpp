#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
vector<int> g[100010];
bool used[100010];

int main()
{
    memset(used, 0, 100000);
    int n, m;
    cin>>n>>m;
    while(m--)
    {
        int a, b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    queue<pii> q; //index, dist
    q.push({1, 0});
    used[1]=1;
    while(!q.empty())
    {
        int x=q.front().first;
        for(int xx:g[x])
        {
            if(!used[xx])
            {
                if(xx==n)
                    cout<<q.front().second<<endl;
                q.push({xx,q.front().second+1});
                used[xx]=1;
            }
        }
        q.pop();
    }
}