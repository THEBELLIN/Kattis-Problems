#include <bits/stdc++.h>
using namespace std;

int main()
{
    long n, s, t;
    bool f=0;
    cin>>n;
    while(!f)
    {
        s=0;
        t=n;
        while(t!=0) //somma cifre
        {
            s+=t%10;
            t=floor(t/10);
        }
        if(n%s==0)
        {
            cout<<n;
            f=1;
        }
        ++n;
    }
    return 0;
}

3
Sanna 1 16/03
Simon 2 16/03
Saga 3 14/10
