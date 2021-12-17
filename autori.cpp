#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s, ans;
	cin>>s;
	ans=ans+s.at(0);
	for(int i=1; i<s.length(); i++)
	{
		if(s.at(i)=='-')
			ans+=s.at(i+1);
	}

	cout<<ans;
	return 0;
}