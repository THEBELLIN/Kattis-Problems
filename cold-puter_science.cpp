#include <bits/stdc++.h>
using namespace std;

int co;

int main()
{
	int n;
	cin>>n;

	for(int i=0; i<n;++i)
	{
		long t;
		cin>>t;
		if(t<0)
			co++;
	}

	cout<<co<<endl;

	return 0;
}
