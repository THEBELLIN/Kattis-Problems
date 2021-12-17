//works but slow

#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

vector<pii> c;
vector<int> timeleft;

bool sort_sec_dec(const pair<int,int> &a, const pair<int,int> &b)
{
    return (a.second > b.second);
};

int main()
{
  int n, k, nn;
  cin>>n>>k;
  nn=n;
  while(nn--)
  {
      int a,b;
      cin>>a>>b;
      pii ab= make_pair(a,b);
      c.push_back(ab);
  }
  sort(c.begin(), c.end(), sort_sec_dec);
  for(int i=0; i<k; i++)
  {
      timeleft.push_back(c[i].first);
  }
  c.erase(c.begin(), c.begin()+k);
  sort(c.begin(), c.end());
  sort(timeleft.begin(), timeleft.end());  //tempi a partire da chi inizia prima
  reverse(c.begin(), c.end()); //a partire da chi inizia più tardi

  int co=0;
  for(int i=0; i<c.size(); i++)
  {
        bool f=0;
        pii t=c[i];
        for(int j=0; j<timeleft.size(); j++)
        {
            if(t.second<timeleft[j])
            {
                timeleft[j]=t.first;
                sort(timeleft.begin(), timeleft.end());
                f=1;
                break;
            }
        }
        if(!f)
            co++;
  }

  cout<<n-co<<endl;
}