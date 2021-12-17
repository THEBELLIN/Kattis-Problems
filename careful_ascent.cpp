#include <bits/stdc++.h>
using namespace std;

int main()
{
	int x, y, s, sum=0;
	double d=0, h;
	cin>>x>>y>>s;
	for(int i=0; i<s; i++)
	{
		double a;
		int lb, ub;
		cin>>lb>>ub>>a;
		d+=(ub-lb)*a;
		sum+=(ub-lb);
	}
	d+=(y-sum);
	h=x/d;
	printf("%f",h);
}