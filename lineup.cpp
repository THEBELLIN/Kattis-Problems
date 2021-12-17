#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> names;

int main()
{
	cin>>n;
	for(int i=0; i<n;++i)
	{
		string s;
		cin>>s;
		names.push_back(s);
	}

	bool cresc=true;
	string s1=names.at(0);
	string s2=names.at(names.size()-1);
	if(s1.compare(s2)<0)
		cresc=true;
	else
		cresc=false;

	bool flag=true;
	for(int i=1; i<n;++i)
	{
		s2=names.at(i);
		if(cresc)
		{	
			flag=(s1.compare(s2)<=0);
		}
		else
		{
			flag=(s1.compare(s2)>=0);
		}
		if(!flag)	break;
		s1=s2;
	}

	if(cresc && flag)
		cout<<"INCREASING";
	if(!cresc && flag)
		cout<<"DECREASING";
	if(!flag)
		cout<<"NEITHER";

	return 0;
}