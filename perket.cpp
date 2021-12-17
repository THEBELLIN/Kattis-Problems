#include <bits/stdc++.h>
using namespace std;

vector<int> s;
vector<int> b;

string numtobinstr(int n, int e);

int main()
{
  int n;
  cin>>n;
  int nn=n;
  while(nn--)
  {
      int so, bi;
      cin>>so>>bi;
      s.push_back(so);
      b.push_back(bi);
  }
  int mindiff=99999999;
  for(int i=1; i<=pow(2,n); i++)
  {
      string mask=numtobinstr(i, n);
      int sour=1, bitt=0;
      for(int j=0; j<n; j++)
      {
          if(mask.at(j)=='1')
          {
              sour*=s[j];
              bitt+=b[j];
          }
      }
      if(abs(sour-bitt)<mindiff)
        mindiff=abs(sour-bitt);
  }
  cout<<mindiff<<endl;
}

string numtobinstr(int n, int e)
{
    string ans="";
    e--;
    while(e>=0)
    {
        if(n>=(pow(2,e)))
        {
            ans=ans+"1";
            n=n%((int)(pow(2,e)));
        }
        else
            ans=ans+"0";
        e--;
    }
    return ans;
}