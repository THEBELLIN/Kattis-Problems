#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long n, ans=3, f;
	cin>>n;
	for(int i=1; i<n; i++)
		ans+=pow(2, i);
	f=pow(ans, 2);
	cout<<f<<endl;
	return 0;
}