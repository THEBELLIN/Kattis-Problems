#include <bits/stdc++.h>
using namespace std;

int main()
{
	int w, n, a=0, wi, le;
	cin>>w>>n;
	while(n--)
	{
		cin>>wi>>le;
		a+=wi*le;
	}
	cout<<a/w;
	return 0;
}