#include <bits/stdc++.h>
using namespace std;

vector<string> on;

void oremove(string s);
void oadd(string s);

int main()
{
    int n,c, d, m, co=0;
    pair <string, int> b[366];
    for(int i=0; i<366; i++)
    {
        b[i].second=-1;
    }
    string na, da;
    cin>>n;
    while(n--)
    {
        cin>>na>>c>>da;
        d=stoi(da.substr(0, 2));
        m=stoi(da.substr(3, 2));
        switch(m)
        {
            case 12: d+=30;
            case 11: d+=31;
            case 10: d+=30;
            case 9: d+=31;
            case 8: d+=31;
            case 7: d+=30;
            case 6: d+=31;
            case 5: d+=30;
            case 4: d+=31;
            case 3: d+=29;
            case 2: d+=31;
            case 1: break;
        }
        if(c>b[d].second)
        {
            if(b[d].second==-1)
                co++;
            oremove(b[d].first);
            oadd(na);
            b[d].first=na;
            b[d].second=c;
        }
    }
    cout<<co<<endl;
    for(int i=0; i<on.size(); i++)
    {
        cout<<on[i]<<endl;
    }
    cout<<d;
    return 0;
}

void oremove(string s)
{
    int i=0;
    while(s!=on[i])
    {
        i++;
    }
    on.erase(on.begin()+i);
}

void oadd(string s)
{
    if(on.size()==0)
        on.push_back(s);
    else
    {
        int i=0;
        while(s<on[i])
        {
            i++;

        }
        on.insert(on.begin()+i, s);
    }
}