#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, m, k, tmp, c=0;
	cin>>n>>m>>k;
	vector<int> p;
	vector<double> h;
	for(int i=0; i<n; i++)
	{
		cin>>tmp;
		p.push_back(tmp);
	}
	for(int i=0; i<m; i++)
	{
		cin>>tmp;
		h.push_back(tmp);
	}
	for(int i=0; i<k; i++)
	{
		cin>>tmp;
		h.push_back((tmp*sqrt(2))/2);
	}
	sort(h.begin(), h.end());
	sort(p.begin(), p.end());

	for(int i=0; i<n; i++)
	{
		bool f=0;
		for(int j=0; j<h.size(); j++)
		{
			if(h[j]<p[i] && !f)
			{
				f=1;
				c++;
				h.erase(h.begin()+j);
			}
		}
	}
	cout<<c<<endl;
}