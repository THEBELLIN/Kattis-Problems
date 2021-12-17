#include <bits/stdc++.h>
using namespace std;

struct paziente
{
	string nomepaziente;
	int infectionlvl;
	int prognumber;
};

struct node
{
	paziente p;
	node *left;
	node *right;
	int height;
	node()
	{
	    left=NULL;
	    right=NULL;
	}
};

class avl_tree
{
	public:
		struct node* root;
		int get_balance(node*);
		node* r_rotation(node*);
		node* l_rotation(node*);
		node* rl_rotation(node*);
		node* lr_rotation(node*);
		node* insert(paziente, node*);
		node* remove(paziente, node*);
		avl_tree()
		{
			root=NULL;
		}
};

bool operator<(const paziente& a, const paziente& b)
{
	return (a.infectionlvl<b.infectionlvl || (a.infectionlvl==b.infectionlvl && a.prognumber>b.prognumber));
}

int compare(paziente k, node* node);
int height(node *node);
node* min_node(node* node);
node* max_node(node* node);
node* newNode(paziente k);

int counter=1;
map<string, pair<int, int>> valori;

int main()
{
	avl_tree avl;

	int c, N;
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
				paziente k;
				k.nomepaziente=name;
				k.infectionlvl=inf;
				k.prognumber=counter;
				avl.root=avl.insert(k, avl.root);
				valori[name]={inf, counter++};
				break;
			}
			case 1:
			{
				paziente d;
				cin>>name>>inf;
				d.nomepaziente=name;
				d.infectionlvl=valori[name].first;
				d.prognumber=valori[name].second;
				avl.root=avl.remove(d, avl.root);
				d.infectionlvl+=inf;
				valori[name].first=d.infectionlvl;
				avl.root=avl.insert(d, avl.root);
				break;
			}
			case 2:
			{
				paziente f;
				cin>>name;
				f.nomepaziente=name;
				f.infectionlvl=valori[name].first;
				f.prognumber=valori[name].second;
				avl.root=avl.remove(f, avl.root);
				break;
			}
			case 3:
			{
			    if(max_node(avl.root)==NULL)
                    cout<<"The clinic is empty"<<endl;
                else
                {
                    paziente last = max_node(avl.root)->p;
                    string lastname = last.nomepaziente;
					cout<<lastname<<endl;
                }
				break;
			}
		}
	}
    return 0;
}

int avl_tree::get_balance(node* parent)
{
	if(parent == NULL)
		return 0;
	return height(parent->left)-height(parent->right);
}

int height(node *node)
{
    if (node==NULL)
        return 0;
    return node->height;
}

node* avl_tree::r_rotation(node* parent)
{
	node* temp = parent->left;
	parent->left = parent->left->right;
	temp->right=parent;
	parent->height=max(height(parent->left), height(parent->right))+1;
	temp->height=max(height(temp->left), height(temp->right))+1;
	return temp;
}

node* avl_tree::l_rotation(node* parent)
{
	node* temp = parent->right;
	parent->right = parent->right->left;
	temp->left=parent;
	parent->height=max(height(parent->left), height(parent->right))+1;
	temp->height=max(height(temp->left), height(temp->right))+1;
	return temp;
}

node* avl_tree::lr_rotation(node* parent)
{
	parent->left=l_rotation(parent->left);
	return r_rotation(parent);
}

node* avl_tree::rl_rotation(node*parent)
{
	parent->right=r_rotation(parent->right);
	return l_rotation(parent);
}

node* avl_tree::insert(paziente k, node* node)
{
	if(node==NULL)
        return(newNode(k));
	//comparazione
	if(compare(k, node)==-1)
		node->left=insert(k,node->left);
	else
		insert(k,node->right);

	//balancing
	node->height=max(height(node->left), height(node->right))+1;
	int balance_parent = get_balance(node);
	int balance_left = get_balance(node->left);
	int balance_right = get_balance(node->right);
	if(balance_parent<-1)
	{
		if(balance_right<=0)
			return r_rotation(node);
		else
			return rl_rotation(node);
	}
	if(balance_parent>1)
	{
		if(balance_left<=0)
			return lr_rotation(node);
		else
			return l_rotation(node);
	}

		return node;
}

node* avl_tree::remove(paziente k, node* node)
{
	if(node==NULL)
		return node;
	if(compare(k, node)==-1)
		node->left=remove(k, node->left);
	else if(compare(k, node)==1)
		node->right=remove(k, node->right);
	else
	{
		if( (node->left==NULL) || (node->right==NULL) )  //1 o 0 figli
        {
            auto temp = node->left!=NULL ? node->left : node->right;
            if(temp==NULL) //0 figli
            {
            	temp=node;
            	node=NULL;
            }
            else //1 figlio
            {
            	*node=*temp;
            	free(temp);
            }
 		}
 		else
 		{
 			auto temp = min_node(node->right);
 			node->p=temp->p;
 			node->right = remove(node->p, temp->right);
 		}
	}
	node->height=max(height(node->left), height(node->right))+1;
	int balance_parent = get_balance(node);
	int balance_left = get_balance(node->left);
	int balance_right = get_balance(node->right);

    if (balance_parent > 1 &&  balance_left>= 0)
        return r_rotation(node);

    if (balance_parent > 1 && balance_left < 0)
    {
        return lr_rotation(node);
    }

    if (balance_parent < -1 && balance_right <= 0)
        return l_rotation(node);

    if (balance_parent < -1 && balance_right > 0)
    {
        return rl_rotation(node);
    }

    return node;
}

int compare(paziente k, node* node) //-1 se minore, 0 se uguale, 1 se maggiore
{
	if(k.infectionlvl!=node->p.infectionlvl)
		if(k.infectionlvl<node->p.infectionlvl)
			return -1;
	else
		if(k.prognumber==node->p.prognumber)
			return 0;
	return 1;
}

node* min_node(node* node)
{
    auto current = node;

    while (current->left != NULL)
        current = current->left;
    return current;
}

node* max_node(node* node)
{
    auto current = node;
    if(node==NULL)
        return NULL;
    while (current->right != NULL)
        current = current->right;
    return current;
}

node* newNode(paziente k)
{
    node* newnode = new node();
    newnode->p = k;
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->height = 0; 
    return(newnode);
}
