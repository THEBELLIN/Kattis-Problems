#include <bits/stdc++.h>
using namespace std;

int main()
{
	int x, n, rem, t;
	cin>>x>>n;
	rem=x;
	for(int i=0; i<n; i++)
	{	
		cin>>t;
		rem+=x-t;
	}
	cout<<rem;
	return 0;
}