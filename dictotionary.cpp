#include<iostream>
#include<string>
using namespace std;
struct node
{
	string word;
	string meaning;
	node *left;
	node *right;

};
class dict
{
public :
	node *root;

	dict()
	{
		root=NULL;

	}
	void acc(node *nn)
	{
		if(root==NULL)
		{
			root=nn;
		}else
		{
			node *cn,*parent;
			cn=root;
			while(cn!=NULL)
			{
				parent=cn;
				if(cn->word > nn->word)
				{
					cn=cn->left;
				}else
				{
					cn=cn->right;
				}
			}if(parent->word > nn->word)
			{
				parent->left=nn;
			}else
			{
				parent->right=nn;
			}
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
	void search()
	{
		string str;
		int cnt=0;
		cout<<"\n enter word to search:::";
		cin>>str;
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
				break;
			}

		}if(flag==0)
		{
			cout<<"\n not found";

		}


		}

	void update()
	{
		string str;
		cout<<"\n enter word to update::";
		cin>>str;
		int flag=0;
				node *cn;
				cn=root;
				while(cn!=NULL)
				{
					if(cn->word > str)
					{
						cn=cn->left;
					}else if(cn->word < str)
					{
						cn=cn->right;
					}else
					{
						cout<<"\n"<<cn->word<<"::"<<cn->meaning;
						cout<<"\n enter new meaning::";
						cin>>cn->meaning;
						cout<<"\n Updated";
						flag=1;
						break;
					}
				}if(flag==0)
				{
					cout<<"\n not found";

				}

	}

	void del(string str)
	{
		
				int cnt=0;
				
				int flag=0;
				node *cn,*parent;
				cn=root;
				if(root==NULL)
				{
					cout<<"\n NULL LIST::";
				}
				while(cn!=NULL && cn->word!=str)
				{
					parent =cn;
					if(cn->word > str)
					{
						cn=cn->left;
					}else if(cn->word < str)
					{
						cn=cn->right;
					}
				}
				
				/*if(cn==root)
				{
					if(cn->right==NULL && cn->left==NULL)
					{
						root=NULL;
						return;
					}	
					
					if(cn->left!=NULL && cn->right!=NULL)	
					 {	
					 	if(cn->left->word > cn->right->word )
						{
							root=cn->left;
							return;
						}else
						{
							root=cn->right;
							return;
						}
					 }
					 
					if(cn->right==NULL && cn->left!=NULL)
					{
						root=cn->left;
						return;
					}
					 
					if(cn->right!=NULL && cn->left==NULL)
					{
						root=cn->right;
						return;
					}
				}*/
				
				
				

				
				if(cn->right==NULL && cn->left==NULL)
				{
				
					if(cn==root)
					{
					root=NULL;
					return;
					}
					if(cn->word < parent->word)
					{
						parent->left=NULL;
					}else
					{
						parent->right=NULL;
					}
					delete cn;
					return;
				}
				
				if(cn->right!=NULL && cn->left==NULL)
				{
					
					if(cn==root)
					{
					root=cn->right;
					delete cn;
					return;
					}
					
					if(parent->word > cn->word)
					{
						parent->left=cn->right;
					}else
					{
						parent->right=cn->right;
					}
					delete cn;
					return;
				}
				if(cn->right==NULL && cn->left!=NULL)
					{
						if(cn==root)
						{
						root=cn->left;
						delete cn;
						return;
						}
									if(parent->word > cn->word)
									{
										parent->left=cn->left;
									}else
									{
										parent->right=cn->left;
									}
					delete cn;
					return;		
					}

				if(cn->right!=NULL && cn->left!=NULL)
				{
					node *tmp;
					tmp=cn->left;
					while(tmp->right!=NULL)
					{
						tmp=tmp->right;
					}
					string x;
					x=tmp->word;
					del(x);
					cn->word=x;
					return;
				}

			


	cout<<"\n not found::";
	}



	};



int main()
{
	node *nn;
	int ch,chhh,c;
	dict d;
	do
	{
	cout<<"\n         ****************_BST PRACTICAL_***********";
	cout<<"\n 1.Insert 2. Display 3.Search 4.update 5.delete" ;
	cin>>chhh;
switch(chhh)
{
case 1:do
		{
		nn=new node();
		nn->left=NULL;
		nn->left=NULL;
		cout<<"\n enter word ";
		cin>>nn->word;
		cout<<"\n enter meaning:";
		cin>>nn->meaning;
		d.acc(nn);
		cout<<"do you...";
		cin>>ch;
		}while(ch==1);
		break;
case 2: d.inorder(d.root);
		break;
case 3: d.search();
		break;
case 4:d.update();
		break;
case 5:string str;
		cout<<"\n enter word to del:::";
				cin>>str;
				d.del(str);
		break;
}cout<<"\n more operation:";
cin>>c;
	}while(c==1);
	return 0;
}
