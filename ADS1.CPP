#include<iostream>
using namespace std;
struct node
 {
  int data;
  node *next;
 };
class ss
 {
       public :
      	int diff;
	node *hn;
	ss()
	{
	 hn=NULL;
	}
	void acc(int data,int a=0)
	 {
	    int ch,d;
		d=data;
		int rep=0;
		
		
		
		if(a==1)
		{
		do
		{
		node *cn,*nn;
		nn=new node();
		nn->next=NULL;
		nn->data=d;
		if(hn==NULL)
		{
			hn=nn;
		}
		else
		{
			node *cc;
			cc=hn;
			while(cc!=NULL)
			{
				if(cc->data==d)
				{
				cout<<"\n repeated element:";
				return;
				}
				cc=cc->next;
			}
			cn=hn;
			while(cn->next!=NULL)
			{
			     cn=cn->next;
			}
			cn->next=nn;
		}
		cout<<"\n do you want to enter new node::";
		cin>>ch;
		if(ch==1)
		{
		  cout<<"\n enter value::";
		  cin>>d;
		}
		}while(ch==1);
		}else
		{
		node *cn,*nn;
		nn=new node();
		nn->next=NULL;
		nn->data=data;
			if(hn==NULL)
			{
			hn=nn;
			}
			else
			{
			cn=hn;
			while(cn->next!=NULL)
			{
			     cn=cn->next;
			}
			cn->next=nn;
			}
		}
		
	 }

	 void disp()
	 {
	 
		node *cn;
		cn=hn;
		cout<<"\n {\t";
		while(cn!=NULL)
		{
			cout<<"\t"<<cn->data;
			cn=cn->next;
		}
		cout<<"\t}";
	 }

		void uni(ss s1,ss s2)
		{
			 diff=0;
			node *cn1,*cn2;
			cn1=s1.hn;
			cn2=s2.hn;
			while(cn1!=NULL)
			{
				acc(cn1->data,0);
				cn1=cn1->next;
			}
			node *cn;
			int fl=0;
			while(cn2!=NULL)
			{      cn=hn;
				fl=0;
			     while(cn!=NULL)
			     {
				if(cn2->data==cn->data)
				{
				   fl=1;
				   break;
				}
				cn=cn->next;
			     }
			     if(fl==0)
			     {
				acc(cn2->data,0);
				diff++;
			     }
			     cn2=cn2->next;
			}
		}

		void inter(ss s1,ss s2)
		{
		node *cn1;
		cn1=s1.hn;
		node *cn2;
		cn2=s2.hn;
		node *cn;
		int fl=0;
		while(cn1!=NULL)
		{
			fl=0;
			cn2=s2.hn;
			while(cn2!=NULL)
			{
			     if(cn2->data==cn1->data)
			     {
				fl=1;
				break;
			     }
			     cn2=cn2->next;
			}
			 if(fl==1)
			 {
				acc(cn1->data);
			 }
			cn1=cn1->next;
		}

		}
		void insertnew()
		{
			int val,pos;
			cout<<"\n enter value::";
			cin>>val;
			cout<<"\n enter position::";
			cin>>pos;
			node *cn,*nn;
			nn=new node;
			nn->data=val;
			nn->next=NULL;
			cn=hn;
			if(pos==1)
			{
				nn->next=hn;
				hn=nn;
			}
			 else
			{
				for(int i=1;i<pos-1;i++)
				{
				cn=cn->next;
				}
				 nn->next=cn->next;
				 cn->next=nn;
			}
		}
		void del()
		{
			int val;
			node *cn,*prv;
			cn=hn;
			cout<<"\n enter value to delete::";
			cin>>val;
			if(hn->data==val)
			{
			hn=hn->next;
			}else
			{
			while(cn!=NULL && cn->data!=val)
			{       prv=cn;
				cn=cn->next;
			}
			prv->next=cn->next;
			}
		}

		void search()
		{
			int val;
			cout<<"\n enter value to search::";
			cin>>val;
			node *cn;
			cn=hn;
			int fl=0;
			while(cn!=NULL)
			{
				if(cn->data==val)
				{
					fl=1;
					break;
				}
				cn=cn->next;
			}
				if(fl==1)
				{
				    cout<<"\n data::"<<val<<"\t is present:";
				}else
				{
				   cout<<"\n data::"<<val<<"\t is absent:";
				}
		}
		
		void count()
		{
			node *cn;
			cn=hn;
			int count1=0;
			while(cn!=NULL)
			{
			
			cn=cn->next;
			count1++;
			}
			cout<<"\n count::"<<count1;
		}
		/*void diff1(ss s1,ss s2)
		{
		       int  diff=0;
			node *cn1,*cn2;
			cn1=s1.hn;
			cn2=s2.hn;
			while(cn1!=NULL)
			{
				acc(cn1->data,0);
				cn1=cn1->next;
			}
			node *cn;
			int fl=0;
			while(cn2!=NULL)
			{      cn=hn;
				fl=0;
			     while(cn!=NULL)
			     {
				if(cn2->data==cn->data)
				{
				   fl=1;
				   break;
				}
				cn=cn->next;
			     }
			     if(fl==0)
			     {
			     	acc(cn2->data);
				diff++;
			     }
			     cn2=cn2->next;
			}
			cout<<"\n Differance is:"<<diff;
		}
		*/
		void diff1(ss s1,ss s2)
		{
		       int  diff=0;
			node *cn1,*cn2;
			cn1=s1.hn;
			cn2=s2.hn;
			node *cn;
			int fl=0;
			while(cn1!=NULL)
			{      cn2=s2.hn;
				fl=0;

			     while(cn2!=NULL)

			     {

				if(cn2->data==cn1->data)

				{

				   fl=1;

				   break;

				}

				cn2=cn2->next;

			     }

			     if(fl==0)

			     {
			     	acc(cn1->data);
				diff++;

			     }

			     cn1=cn1->next;

			}
			cout<<"\n Differance is:"<<diff;
		}
 };
int main()
{

  ss s,s1,s2,s3,s4,s5;


  int ch,c,n,node1;
  do
  {
  	cout<<"\n !!!!!!!!_SET OPERATIONS_!!!!!!!!!"; 
	cout<<"\n 1_perform operations on set1      ::";
	cout<<"\n 2_perform operation on set2       ::";
	cout<<"\n 3_UNION of set 1 and set 2        ::";
	cout<<"\n 4_INTERSECTION of set 1 and set 2 ::";
	cout<<"\n 5_Differance of set1 and set2     ::";
	cin>>ch;
	switch(ch)
	{
		case 1: 
			cout<<"\n !!!!!!!!_SET OPERATIONS ON SET 1_!!!!!!!!!";
			cout<<"\n 1_create set 		  :";
			cout<<"\n 2_display set           :";
			cout<<"\n 3_Insert new node in set1:";
			cout<<"\n 4_Delete node from set1 :";
			cout<<"\n 5_search in set1       :";
			cout<<"\n 6_count in set1       :";
			
			
			cin>>c;
			switch(c)
			{
				case 1: cout<<"\n etnter first node:";
					cin>>node1;
					s1.acc(node1,1);
					break;
				case 2: s1.disp();
					break;
				case 3: s1.insertnew();
					cout<<"\n done!!";
					break;
				case 4: s1.del();
					cout<<"\n done!!";
					break;
				case 5: s1.search();
					break;
				case 6: s1.count();
					break;
			}
			break;
		case 2: 
			cout<<"\n !!!!!!!!_SET OPERATIONS ON SET 2_!!!!!!!!!";
			cout<<"\n 1_create set 		  :";
			cout<<"\n 2_display set           :";
			cout<<"\n 3_Insert new node in set2:";
			cout<<"\n 4_Delete node from set2  :";
			cout<<"\n 5_search(contain) in set2       :";
			cout<<"\n 6_Count of set2       :";
			cin>>c;

			switch(c)
			{
				case 1: cout<<"\n etnter first node:";
					cin>>node1;
					s2.acc(node1,1);
					break;
				case 2: s2.disp();
					break;
				case 3: s2.insertnew();
					cout<<"\n done!!";
					break;
				case 4: s2.del();
					cout<<"\n done!!";
					break;
				case 5: s2.search();
					break;
				case 6: s2.count();
					break;
			}
			break;
		case 3: s.uni(s1,s2);
			cout<<"\n UNION;:";
			s.disp();
			break;

		case 4: s3.inter(s1,s2);
			cout<<"\n INTERSECTION;:";
			s3.disp();
			break;
		case 5: cout<<"\n s1 - s2 :";
			s4.diff1(s1,s2);
			s4.disp();
			cout<<"\n s2-s1 :";
			s5.diff1(s2,s1);
			s5.disp();
			break;
	}

  cout<<"\n do you want to perform more opertion::(1/0)";
  cin>>n;
  }while(n==1);
  
  return 0;
}
