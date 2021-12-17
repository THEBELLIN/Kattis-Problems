#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, t1, t2, m1, m2, tot;
	while(1)
	{
		tot=0;
		cin>>n;
		if(n==-1)
			break;
		cin>>m1>>t1;
		tot+=(m1*t1);
		n--;
		while(n--)
		{
			cin>>m2>>t2;
			tot+=(m2*(t2-t1));
			t1=t2;
			m1=m2;
		}
		cout<<tot<<" miles"<<endl;
	}
	
	return 0;
}