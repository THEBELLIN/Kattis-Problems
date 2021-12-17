//TO FINISH
#include <bits/stdc++.h>
using namespace std;

typedef long long ll
vector<ll> d;

ll rev(ll num);

ll n, s, n1;

int main()
{
    cin>>n>>s;
    while(n--)
    {
        cin>>n1;
        d.push_back(n1);
        d.push_back(rev(n1));
    }
    return 0;
}

ll rev (ll num)
{
    //cifre invertibili: 0, 1, 2, 5, 6, 8, 9
    string nums=num.to_string();
    bool r=1;
    //check reversability
    for(int i=0; i<nums.length(); i++)
    {
        if(nums.at(i)=='3' || nums.at(i)=='4' || nums.at(i)=='7') //not reversable
            r=0;
    }
    //reverse TODO
    if(r) 
    {
        string revs;
        d.push_back(reversed);
    }
}
