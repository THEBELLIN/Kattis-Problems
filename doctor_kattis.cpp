#include <bits/stdc++.h>
using namespace std;

struct paziente
{
	string nomepaziente;
	int infectionlvl;
	int prognumber;
};

bool operator<(const paziente& a, const paziente& b)
	{
		return (a.infectionlvl<b.infectionlvl || (a.infectionlvl==b.infectionlvl && a.prognumber>b.prognumber));
	}

void insertion(string catName, int infectionLevel, int number);
void ArriveAtClinic(string catName, int infectionLevel);
void UpdateInfectionLevel(string catName, int increaseInfection);
void Treated(string catName);
paziente Query();
void swap(int i, int j);
void down_heap_bubbling(int i);

int N;
vector<paziente> listapaz;
int numbercounter=1;

string nametemp;
int infectiontemp;
int numbertemp;

int main()
{
	int c;
	string name;
	int inf;
	cin>>N;
	for(int i=0; i<N;i++)
	{
		cin>>c;
		switch(c)
		{
			case 0:
			{
				cin>>name>>inf;
				ArriveAtClinic(name, inf);
				break;
			}
			case 1:
			{
				cin>>name>>inf;
				UpdateInfectionLevel(name, inf);
				break;
			}
			case 2:
			{
				cin>>name;
				Treated(name);
				break;
			}
			case 3:
			{
				string lastname = Query().nomepaziente;
				if(lastname=="null")
					cout<<"The clinic is empty"<<endl;
				else
					cout<<lastname<<endl;
				break;
			}
		}
	}
    return 0;
}

void ArriveAtClinic(string catName, int infectionLevel)
{
	insertion(catName, infectionLevel, numbercounter++);
}

void insertion(string catName, int infectionLevel, int number) //insertion heap O(logn)
{
	paziente k = {catName, infectionLevel, number};
	listapaz.push_back(k);
	push_heap(listapaz.begin(), listapaz.end());
}

void UpdateInfectionLevel(string catName, int increaseInfection)
{
	int newlevel=0;
	int hisnumber;
	for(int i=0; i<listapaz.size();++i)
	{
		if(listapaz[i].nomepaziente==catName)
		{
			newlevel=increaseInfection+listapaz[i].infectionlvl;
			hisnumber=listapaz[i].prognumber;
			break;
		}
	}
	Treated(catName);
	insertion(catName, newlevel, hisnumber);
}

void Treated(string catName) //O(logn) se Treated(Query());
{
    int s= listapaz.size()-1;
    int j;
	for(int i=0; i<=s;++i)
	{
		if(listapaz[i].nomepaziente==catName && i!=s) //O(n) linearsearch
        {
            listapaz[i].nomepaziente=listapaz[s].nomepaziente;
            listapaz[i].infectionlvl=listapaz[s].infectionlvl;
            listapaz[i].prognumber=listapaz[s].prognumber;
            j=i;
            break;
        }
	}
	listapaz.pop_back();
	down_heap_bubbling(j);
}

paziente Query()
{
	if(listapaz.size()==0)
		return {"null", -1, -1};
	return listapaz.front();
}

void swapPaz (int i, int j)
{
	nametemp=listapaz[i].nomepaziente;
	listapaz[i].nomepaziente=listapaz[j].nomepaziente;
	listapaz[j].nomepaziente=nametemp;

	infectiontemp=listapaz[i].infectionlvl;
	listapaz[i].infectionlvl=listapaz[j].infectionlvl;
	listapaz[j].infectionlvl=infectiontemp;

	numbertemp=listapaz[i].prognumber;
	listapaz[i].prognumber=listapaz[j].prognumber;
	listapaz[j].prognumber=numbertemp;
}

void down_heap_bubbling(int i)
{
	int j;
	while(i<(listapaz.size()-1)/2)
	{
		if(listapaz[2*i+1].infectionlvl>listapaz[2*i+2].infectionlvl || (listapaz[2*i+1].infectionlvl==listapaz[2*i+2].infectionlvl && listapaz[2*i+1].prognumber<listapaz[2*i+2].prognumber))
			j=2*i+1;
		else
			j=2*i+2;
		if(listapaz[i].infectionlvl<listapaz[j].infectionlvl || (listapaz[i].infectionlvl==listapaz[j].infectionlvl && listapaz[i].prognumber>listapaz[j].prognumber))
		{
			swapPaz(i, j);
			i=j;
		}
		else
		{
			break;
		}
	}
}

//TODO
//implementare AVL
//mantenere in memoria indice e nome del maggiore in modo da avere velocemente treated(query()) dopo una query()