#include<iostream>
using namespace std;
struct node
{
	int data;
	node *left;
	node *right;
	int lth,rth;
};
class TBST
{
	public:
	node *root,*dummy;
	TBST()
	{
		root=NULL;
	}
	void Create()
	{
		node *nn;
		int ch;
		do
		{		
			nn=new node();
			
			nn->left=nn->right=NULL;
			cout<<"Enter the data to store in node \n";
			cin>>nn->data;
			nn->lth=1;
			nn->rth=1;

			if(root==NULL)
			{
				dummy=new node();
				dummy->data=10;
				dummy->left=dummy->right=NULL;
				root=nn;
				dummy->left=root;
				nn->left=dummy;
				nn->right=dummy;

			}
			else
			{
				node *cn;
				cn=root;
				while(1)
				{
					if(cn->data > nn->data)
					{
						if(cn->lth==1)
						{
							
							cn->lth=0;
							nn->left=cn->left;
							nn->right=cn;
							cn->left=nn;
							
							break;
						}
						else
						{
							cn=cn->left;
						}
					}
					else if(cn->data <nn->data)
					{
						if(cn->rth==1)
						{
							cn->rth=0;
							nn->right=cn->right;
							nn->left=cn;
							cn->right=nn;
							break;
						}
						else
						{
							cn=cn->right;
						}
					}
				}
		   	 }
		   	 cout<<"\n cont:";
		   	 cin>>ch;
		}while(ch==1);
		
	}
	void Display()
	{
		node *temp;
		temp=root;

		while(temp!=dummy)
		{
			while(temp->lth==0)
			{
				temp=temp->left;
			}
			cout<<temp->data<<"\t";

			while(temp->rth==1)
			{
				temp=temp->right;
				if(temp!=dummy)
				{
					cout<<temp->data<<"\t" ;
				}
				else
				{
					return;
				}
			}
			temp=temp->right;
		}
		
	}
	void pre()
	{
		node *temp;
		temp=root;

		while(temp!=dummy)
		{
			 cout<<temp->data<<"\t"; 
			while(temp->lth==0)
			{
				
				temp=temp->left;
				cout<<temp->data<<"\t"; 
			}
			
				
			while(temp->rth==1) 	
			{
				temp=temp->right;
				if(temp==dummy)
				{
					return  ;
				}
				
			}
			temp=temp->right;
		}
		
	}
	
	void post()
	{
		node *cn;
		cn=root;
		int arr[10];
		int i=0;

		while(cn!=dummy)
		{
			
			while(cn->rth==0)
			{
			arr[i]=cn->data;
			i++;
			cn=cn->right;
			}
			arr[i++]=cn->data;
			
			while(cn->lth==1 && cn->left!=dummy )
			{
				cn=cn->left;
			}
			cn=cn->left;
			
		}
		i--;
		cout<<"\n:";
		for(int k=i;k>=0;k--)
		{
			cout<<"\t"<<arr[k];
		}
		cout<<"\n";
	}
	
	
};
int main()
{
		TBST t1;
		
		int cn;
		int ch;
		do
		{
			cout<<"\n         ****************_BST PRACTICAL_***********";
			cout<<"\n 1.Create 2. Inorder 3.PreOrder 4.Post  ";
			cin>>cn;
			switch(cn)
			{
			case 1:t1.Create();	
				break;
			case 2:cout<<"\n INODER::";
				t1.Display();
				break;
			case 3:cout<<"\n PREORDER::";
				t1.pre();
				break;
			case 4:	cout<<"\n POSTODER::";
				t1.post();
				break;
				
			
			}
			cout<<"\n more operation::";
			cin>>ch;
		
		}while(ch==1);
		

		return 0;
}

