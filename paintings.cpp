#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, m;
    cin>>t;
    while(t--)
    {
        cin>>n;
        string c[n]; //colori in ordine di preferenza
        bool l[n][n]; //matrice: per ogni riga i si indicano con 1 i j colori che vanno bene
        for(int i=0; i<n; i++) //initialize matrix
        {
            for(int j=0 ; i<n; j++)
            {
                if(i==j)
                    l[i][j]=0;
                else
                    l[i][j]=1;
            }
        }
        for(int i=0; i<n; i++) //input colors
        {
            cin>>c[i];
        }
        cin>>m;
        for(int i=0; i<m; i++) //input dislikes
        {
            string tmp1, tmp2;
            int t1, t2;
            cin>>tmp1>>tmp2;
            for(int j=0; j<n; j++)
            {
                if(tmp1==c[j])
                    t1=j;
                if(tmp2==c[j])
                    t2=j;
            }
            l[t1][t2]=0;
            l[t2][t1]=0;
        }
    }
}