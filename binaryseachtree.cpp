//============================================================================
// Name        : BST.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

struct node
{
	string word;
	string mean;
	node *l,*r;

};

class Dict
{


public:
		node *root;
		Dict()
		{
			root=NULL;
		}

		void insert()
		{
			node *cn,*parent;
			node *nn;
			char ch;

			do
			{
			nn=new node;
			cout<<"\nEnter the word:";
			cin>>nn->word;
			cout<<"\nEnter the Meaning:";
			cin>>nn->mean;
			nn->l=nn->r=NULL;

			if(root==NULL)
			{
				root=nn;
			}

			else
			{
				cn=root;

				while(cn!=NULL)
				{
					parent=cn;

					if(cn->word==nn->word)
					{
						cout<<"\nWord Already inserted";
					}

					else if(cn->word>nn->word)
					{
						cn=cn->l;
					}

					else
					{
						cn=cn->r;
					}

				}

				if(parent->word>nn->word)
					parent->l=nn;
				else
					parent->r=nn;
			}

			cout<<"\nDo you want to insert more words(y/n)";
			cin>>ch;
			}while(ch=='y'||ch=='Y');
		}


		void inorder(node *r)
		{
			if(r!=NULL)
			{
				inorder(r->l);
				cout<<"\n"<<r->word<<" --- "<<r->mean;
				inorder(r->r);
			}

		}

		void search()
		{
			string key;
			cout<<"\nEnter the word to be searched:";
			cin>>key;

			if(root==NULL)
			{
				cout<<"\nDictionary is empty";
				return;
			}

			node *cn=root;
			while(cn!=NULL)
			{
				if(cn->word==key)
				{
					cout<<"Meaning is:"<<cn->mean;
					return;
				}

				if(cn->word>key)
					cn=cn->l;
				else cn=cn->r;
			}
			cout<<"\nNot found!";
		}

		void del(string key)
		{
			node *cn=root;
			node *parent;
			while(cn!=NULL&&cn->word!=key)
			{
				parent =cn;
				if(cn->word>key)
					cn=cn->l;
				else
					cn=cn->r;

			}

			if(cn==NULL)
			{
				cout<<"\nWord not found";
				return;
			}

			if(cn->l==NULL&&cn->r==NULL)
			{
				if(cn==root)
				{
					root=NULL;
					delete cn;
					return;
				}
				if(cn->word>parent->word)
					parent->r=NULL;
				else
					parent->l=NULL;
			delete cn;
			}

			else if(cn->l==NULL&&cn->r!=NULL)
			{
				if(cn==root)
				{
					root=cn->r;
					delete cn;
					return;
				}
				if(cn->word>parent->word)
					parent->r=cn->r;
				else
					parent->l=cn->r;
			delete cn;
			}

			else if(cn->l!=NULL&&cn->r==NULL)
			{
				if(cn==root)
				{
					root=cn->l;
					delete cn;
					return;
				}
				if(cn->word>parent->word)
					parent->r=cn->l;
				else
					parent->l=cn->l;
			delete cn;
			}

			else if(cn->l!=NULL&&cn->r!=NULL)
			{
				node *temp;
				temp=cn->l;
				while(temp->r!=NULL)
					temp=temp->r;
				string x;
				x=temp->word;
				del(temp->word);
				cn->word=x;
			}
		}

		void update()
		{
			string key;
			cout<<"\nEnter the word to be updated:";
			cin>>key;

			if(root==NULL)
			{
				cout<<"\nDictionary is empty";
				return;
			}

			node *cn=root;
			while(cn!=NULL)
			{
				if(cn->word==key)
				{
					cout<<"Meaning is:"<<cn->mean;
					cout<<"\nEnter new meaning:";
					cin>>cn->mean;
					return;
				}

				if(cn->word>key)
					cn=cn->l;
				else cn=cn->r;
			}
			cout<<"\nNot found!";
		}
};


int main()
{
	Dict D;
	string m;
	int choice;
	do
	{
		cout<<"\n\t\t\t*****MENU*****";
		cout<<"\n\t\t\t1.INSERT WORD";
		cout<<"\n\t\t\t2.DISPLAY ASCENDING";
		cout<<"\n\t\t\t3.SEARCH MEANING OF WORD";
		cout<<"\n\t\t\t4.DELETE WORD";
		cout<<"\n\t\t\t5.UPDATE MEANING OF WORD";
		cout<<"\n\t\t\t6.EXIT";
		cout<<"\nEnter your choice:";
		cin>>choice;

		switch(choice)
		{
		case 1: D.insert();
				break;

		case 2: if(D.root==NULL)
					cout<<"\nTREE IS EMPTY";
				else
					D.inorder(D.root);
				break;

		case 3:	D.search();
				break;

		case 4:
				cout<<"\nEnter the word to be deleted:";
				cin>>m;
				D.del(m);
				break;

		case 5: D.update();
				break;

		case 6: break;

		default: cout<<"\nEnter valid choice!";
		}

	}while(choice!=6);


	return 0;
}
