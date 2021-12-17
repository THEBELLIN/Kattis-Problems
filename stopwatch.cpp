#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,t1, t2, tot=0;
	cin>>n;
	if(n%2!=0)
		cout<<"still running";
	else
	{
		for(int i=1; i<=n; i++)
		{
			if(i%2!=0)
				cin>>t1;
			else
			{
				cin>>t2;
				tot+=t2-t1;
			}
		}
		cout<<tot;
	}
	return 0;
}