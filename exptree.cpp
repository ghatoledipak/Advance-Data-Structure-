#include<iostream>
#include<stack>
#include<queue>
using namespace std;
struct node
{
	char op;
	node *left ,*right;
};
class stack1
{
public:
	node *s[10];
	int top;
	stack1()
	{
		top=-1;
	}

	void push(node *cn)
	{
		s[++top]=cn;
	}
	node* pop()
	{
		node *cn=s[top];
		top--;
		return cn;
	}

	int isemp()
	{
		if(top==-1)
		{
			return 1;
		}else
		{
			return 0;
		}
	}
	char gettop()
	{
		return s[top]->op;
	}
};
class exp
{
public:
	stack1 opr,opn;
	node *root;
	exp()
	{
		root=NULL;
	}

	int pri(char ch)
	{
		switch(ch)
		{
		case '+' :  return 1;
					break;
		case '-' :  return 1;
						break;
		case '*' :  return 2;
						break;
		case '/' :  return 2;
						break;

		case '^' :  return 3;
						break;
		}
	}

	void create()
	{
		char str[10];
		cout<<"enter expression tree";
		cin>>str;
		node *nn;
		int i=0;
		while(str[i]!='\0')
		{
			nn=new node();
			nn->left=nn->right=NULL;
			nn->op=str[i];
			if(str[i]=='+' ||str[i]=='-' ||str[i]=='^' ||str[i]=='*' ||str[i]=='/' )
			{
				if(opr.top==-1)
				{
					opr.push(nn);
				}else
				{
					node *cn;
					char tok=opr.gettop();
					if(pri(str[i]) < pri(tok))
					{
						cn=opr.pop();
						cn->right=opn.pop();
						cn->left=opn.pop();
						opn.push(cn);
						opr.push(nn);
					}else
					{
						opr.push(nn);
					}
				}
			}else
			{
				opn.push(nn);
			}
			i++;
		}
		while(opr.top!=-1)
		{
			node *cn;
			cn=opr.pop();
			cn->right=opn.pop();
			cn->left=opn.pop();
			opn.push(cn);
		}
		root=opn.pop();
	}

	void ino(node *cn)
	{
		if(cn!=NULL)
		{
			ino(cn->left);
			cout<<"\n "<<cn->op;
			ino(cn->right);
		}
	}
	void pre(node *cn)
		{
			if(cn!=NULL)
			{
				cout<<"\n "<<cn->op;
				ino(cn->left);
				ino(cn->right);
			}
		}
	void post(node *cn)
			{
				if(cn!=NULL)
				{
					ino(cn->left);
					ino(cn->right);
					cout<<"\n "<<cn->op;

				}

			}


};
int main()
{
	exp p;
	p.create();
	p.ino(p.root);
	p.pre(p.root);
	p.post(p.root);

	return 0;
}
