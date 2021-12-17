#include <bits/stdc++.h>
using namespace std;

int sum_digits(int a); 

int main()
{
	int m, n=0, x, l, d, t;
	cin>>l>>d>>x;
	for(int i=l; i<=d; i++)
	{
		t=sum_digits(i);
		if(t==x)
		{
			if(n==0)
				n=t;
			m=t;
		}
	}
	cout<<n<<endl;
	cout<<m<<endl;;
	return 0;
}

int sum_digits(int a)
{
	int ans=0;
	while(a!=0)
	{
		ans+=a%10;
		a/=10;
	}
	return ans;
}