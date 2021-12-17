#include <bits/stdc++.h>
using namespace std;

int main()
{
	int pm=0, nm, ts, s;
	for(int i =1; i<=5; i++)
	{
		ts=0;
		int a=4;
		while(a--)
		{
			cin>>s;
			ts+=s;
		}
		if(ts>pm)
		{
			pm=ts;
			nm=i;
		}
	}
	cout<<nm<<" "<<pm;
	return 0;
}