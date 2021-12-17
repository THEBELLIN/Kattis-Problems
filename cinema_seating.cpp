#include <bits/stdc++.h>
using namespace std;

int cinema[1000][1000];
bool posti[1000][1000] = {0};
int counter[10];
int r,c;

void updatenearby (int rr, int cc);

int main()
{
 //first non cinema
  cin>>r>>c;
  int n;
  cin>>n;
  for(int i=0; i<r; i++)
  {
      for(int j=0; j<c; j++)
      {
          cinema[i][j]=0;
      }
  }
  while(n--)
  {
    int rr, cc;
    cin>>rr>>cc;
    rr--;
    cc--;
    posti[rr][cc]=1;
    updatenearby(rr,cc);
  }
  for(int i=0; i<9; i++)
  {
      counter[i]=0;
  }
  for(int i=0; i<r; i++)
  {
      for(int j=0; j<c; j++)
      {
          //cout<<cinema[i][j]<<" ";
          if(posti[i][j])
            counter[cinema[i][j]]++;
      }
      //cout<<endl;
  }
  for(int i=0; i<9; i++)
  {
      cout<<counter[i]<<" ";
  }
}

void updatenearby(int rr, int cc) //si poteva fare in modo più veloce, ma ci stavo smadonnando da troppo tempo
{
    if(rr==0 && cc==0) //angolo alto sx
    {
        cinema[0][1]++;
        cinema[1][1]++;
        cinema[1][0]++;
        return;
    }
     if(rr==0 && cc==c-1) //angolo alto dx
    {
        cinema[0][cc-1]++;
        cinema[1][cc-1]++;
        cinema[1][cc]++;
        return;
    }
     if(rr==r-1 && cc==0) //angolo basso sx
    {
        cinema[rr][1]++;
        cinema[rr-1][1]++;
        cinema[rr-1][0]++;
        return;
    }
     if(rr==r-1 && cc==c-1) //angolo basso dx
    {
        cinema[rr][cc-1]++;
        cinema[rr-1][cc-1]++;
        cinema[rr-1][cc]++;
        return;
    }
    if(rr==0) //bordo alto
    {
        cinema[rr][cc-1]++;
        cinema[rr][cc+1]++;
        cinema[rr+1][cc-1]++;
        cinema[rr+1][cc]++;
        cinema[rr+1][cc+1]++;
        return;
    }
       if(rr==r-1) //bordo basso
    {
        cinema[rr][cc-1]++;
        cinema[rr][cc+1]++;
        cinema[rr-1][cc-1]++;
        cinema[rr-1][cc]++;
        cinema[rr-1][cc+1]++;
        return;
    }
       if(cc==0) //bordo sx
    {
        cinema[rr-1][cc]++;
        cinema[rr+1][cc]++;
        cinema[rr-1][cc+1]++;
        cinema[rr][cc+1]++;
        cinema[rr+1][cc+1]++;
        return;
    }
        if(cc==c-1) //bordo dx
    {
        cinema[rr-1][cc]++;
        cinema[rr+1][cc]++;
        cinema[rr-1][cc-1]++;
        cinema[rr][cc-1]++;
        cinema[rr+1][cc-1]++;
        return;
    }

    cinema[rr-1][cc-1]++;
    cinema[rr-1][cc]++;
    cinema[rr-1][cc+1]++;
    cinema[rr][cc-1]++;
    cinema[rr][cc+1]++;
    cinema[rr+1][cc-1]++;
    cinema[rr+1][cc]++;
    cinema[rr+1][cc+1]++;
    return;
}