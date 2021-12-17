#include <bits/stdc++.h>
using namespace std;

int n, p, m;
unordered_map<string, int> points;

int main()
{
	cin>>n>>p>>m;

	for(int i =0; i<n; i++)
	{
		string s;
		cin>>s;
		points.insert({s,0});
	}

	bool flag=false;
	for(int i=0; i<m;++i)
	{
		string s;
		int score;
		cin>>s>>score;
		points[s]+=score;
		if(points[s]>=p)
		{
			points[s]=-99999999;
			cout<<s<<" wins!"<<endl;
			flag=true;
		}
	}

	if(!flag)
		cout<<"No winner!"<<endl;
	return 0;
}