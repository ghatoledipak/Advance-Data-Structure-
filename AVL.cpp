#include<iostream>
#include<string>
#include<math.h>
using namespace std;
struct node
{
	string word,meaning;
	node *left,*right;

};
class avl
{
public:
	node *root;
	avl()
	{
		root=NULL;
	}

	node * insert(node *roott,node *nn)
	{
		if(roott==NULL)
		{
			roott=nn;
		}else
		{
			string key=nn->word;
			if(nn->word < roott->word)
			{
				roott->left=insert(roott->left,nn);

				int h1,h2;
				h1=height(roott->left);
				h2=height(roott->right);
				int c=h1-h2;
				if(c==2 || c==-2)
				{
					if(roott->left->word > key)
					{
						roott=LL(roott);
					}else
					{
						roott=LR(roott);
					}
				}
			}
			else
			{
				roott->right=insert(roott->right,nn);
				int h1,h2;
				h1=height(roott->left);
				h2=height(roott->right);
				int c=h1-h2;
				if(c==2 || c==-2)
				{
					if(roott->right->word < key)
					{
						roott=RR(roott);
					}else
					{
						roott=RL(roott);
					}
				}
			}
		}
		return roott;
	}

	node * LL(node *parent )
	{
		node *tmp;
		tmp=parent->left;
		parent->left=tmp->right;
		tmp->right=parent;
		parent =tmp;
		return parent;
	}

	node * RR(node *parent )
		{
			node *tmp;
			tmp=parent->right;
			parent->right=tmp->left;
			tmp->left=parent;
			parent =tmp;
			return parent;
		}

	node *LR(node *parent)
	{
		node *tmp;
		parent->left=RR(parent->left);
		parent=LL(parent);
		return parent;
	}


	node *RL(node *parent)
		{
			node *tmp;
			parent->right=LL(parent->right);
			parent=RR(parent);
			return parent;
		}

	int height(node *tmp)
	{
		if(tmp==NULL)
		{
			return -1;
		}else if(tmp->left==NULL && tmp->right==NULL)
		{
			return 0;
		}

		return (1+ max(height(tmp->left),height(tmp->right)));
	}
	int max(int a,int b)
	{
		if(a>b)
		{
			return a;
		}else
		{
			return b;
		}
	}

	void pre(node *tmp)
	{
		if(tmp!=NULL)
		{
			cout<<"\n"<<tmp->word<<"::"<<tmp->meaning;
			pre(tmp->left);
			pre(tmp->right);
		}
	}

	void inorder(node *tmp)
					{
						if(tmp!=NULL)
						{
							inorder(tmp->left);
							cout<<"\n"<<tmp->word<<"::"<<tmp->meaning;
							inorder(tmp->right);
						}
					}

	int search(string str)
				{

					int cnt=0;

					int flag=0;
					node *cn;
					cn=root;
					while(cn!=NULL)
					{
						cnt++;
						if(cn->word > str)
						{
							cn=cn->left;
						}else if(cn->word < str)
						{
							cn=cn->right;
						}else
						{
							cout<<"\n"<<cn->word<<"::"<<cn->meaning;
							cout<<"\n no of comparison needed::"<<cnt;
							flag=1;
							return 1;
							break;
						}

					}if(flag==0)
					{
						cout<<"\n not found";
						return 0;
					}


					}



};
int main()
{
int c,ch;
avl d;
node *nn;
do
{
	cout<<"\n *****************_AVL DICTIONARY_*****************";
	cout<<"\n 1. INSERT INTO AVL:";
	cout<<"\n 2. PREORDER::";
	cout<<"\n 3. INORDER::";
	cout<<"\n 4. SEARCH::";
	cout<<"\n enter operation that you wan to do-->";
	cin>>ch;

	switch(ch)
	{
	case 1:
			nn=new node();
			nn->left=nn->right=NULL;
			cout<<"\n enter word and meaning of a node -->";
			cin>>nn->word>>nn->meaning;
			d.root=d.insert(d.root,nn);
			break;
	case 2: cout<<"\n **************PREORDER**************";
			d.pre(d.root);
			break;
	case 3: cout<<"\n **************INORDER**************";
			d.inorder(d.root);
			break;
	case 4:	string str;
			int a;
			cout<<"\n enter word to search:::";
			cin>>str;
			a=d.search(str);

	}
	cout<<"\n more operation::(0/1)";
	cin>>c;
}while(c==1);

	return 0;
}
