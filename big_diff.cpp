#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	size_t i;
	while(getline(cin, s))
	{
		unsigned long long a, b, d;
		a=stoll(s, &i);
		s=s.substr(i);
		b=stoll(s, &i);
		if(a>b)
			d=a-b;
		else
			d=b-a;
		cout<<d<<endl;
	}
	return 0;
}

