#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
vector<int> g[100000];
int d[100000];

void dfs(int index);

int main()
{
    memset(d,-1,100000);
    int n, m;
    cin>>n>>m;
    while(m--)
    {
        int a, b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    d[1]=0;
    dfs(1);
    cout<<d[n]-1<<endl;
}

void dfs(int index)
{
    for(int x:g[index])
    {
        if(d[x]==-1 || d[x]>d[index]+1)
        {
            d[x]=d[index]+1;
            dfs(x);
        }
    }
}