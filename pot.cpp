#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	long result=0;
	while(n--)
	{
		long number;
		cin>>number;
		string t=to_string(number);
		string b = t.substr(0, t.length()-1);
		string e = t.substr(t.length()-1);
		long bb=stoi(b);
		long ee=stoi(e);
		result+=pow(bb, ee);
	}
	cout<<result<<endl;
	return 0;
}
