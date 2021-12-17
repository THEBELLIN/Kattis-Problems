#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	float qualy=0;
	cin>>n;
	while(n--)
	{
		float a, b;
		cin>>a>>b;
		qualy+=a*b;
	}
	cout<<qualy<<endl;
	return 0;
}