#include <bits/stdc++.h>
using namespace std;

struct paziente
{
	string nome;
	int infection;
	int number;

	bool operator<(const paziente &d) const
	{
		if(infection != d.infection)
			return infection>d.infection;
		return
			number<d.number;
	}
};

int prognumber=1;
set<paziente> listapaz;
map<string, pair<int, int>> valori;

int main()
{
	int n,c;
	cin>>n;
	string nome;
	int inf;
	
	while(n--)
	{
		cin>>c;
		switch(c)
		{
			case 0:
			{
				paziente a;
				cin>>nome>>inf;
				a.nome=nome;
				a.infection=inf;
				a.number=prognumber;

				listapaz.insert(a);
				valori[nome]={inf, prognumber++};
				break;
			}
			case 1:
			{
				paziente a;
				cin>>nome>>inf;
				a.nome=nome;
				a.infection=valori[nome].first;
				a.number=valori[nome].second;

				auto it = listapaz.find(a);
				paziente old = *it;							
				listapaz.erase(it);
				old.infection+=inf;
				listapaz.insert(old);					
				valori[nome].first=old.infection;
				break;
			}
			case 2:
			{
				paziente a;
				cin>>nome;
				a.nome=nome;
				a.infection=valori[nome].first;
				a.number=valori[nome].second;
				listapaz.erase(listapaz.find(a));
				break;
			}
			default:
			{
				if(listapaz.empty())
					cout<<"The clinic is empty"<<endl;
				else
					cout<<(*listapaz.begin()).nome<<endl;
			}
		}
	}
	return 0;
}

//TODO
//implementare AVL per avere sempre prestazioni logaritmiche