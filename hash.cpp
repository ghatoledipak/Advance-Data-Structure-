#include<iostream>
#include<string>
using namespace std;
struct HT
{
	long int telephone;
	string name;
	string addr;
};
class hash1
{
	HT hash[10];
	int flag[10],chain[10],n;
public:
	hash1()
	{
		n=10;
		for(int i=0;i<10;i++)
		{
			hash[i].telephone=0;
			hash[i].addr=" ";
			hash[i].name=" ";
			flag[i]=0;
			chain[i]=-1;
		}
	}

	void linear_prob_without_repl()
	{
		long int telephone;
			string name;
			string addr;
			cout<<"\n enter name:";
			cin>>name;
			cout<<"\n enter Tel no:";
			cin>>telephone;
			cout<<"\n enter address:";
			cin>>addr;
			int pos;
			pos=(telephone)%n;
			for(int i=0;i<n;i++)
			{
				if(flag[pos]==0)
				{
					hash[pos].telephone=telephone;
					hash[pos].addr=addr;
					hash[pos].name=name;
					cout<<"\n done ";
					flag[pos]=1;
					return;
				}
				pos=(pos+1)%n;
			}
			cout<<"\n not found....!!!!";
			return;
	}
		void search_linear_prob_without_repl()
		{
			long int telephone;
			int pos;
			cout<<"\n enter telephone :";
			cin>>telephone;
			pos=(telephone)%n;
			for(int i=0;i<n;i++)
			{
				if(hash[pos].telephone ==telephone)
				{
					cout<<"\n found .....!!";
					cout<<"\n"<<hash[pos].name<<"\t";
					cout<<hash[pos].telephone<<"\t";
					cout<<hash[pos].addr<<"\t";
					return;
				}
				pos=(pos+1)%n;
			}
			cout<<"\n element not found....!!!";
			return;
		}
	void disp()
	{
			cout<<"\n name\t telephone\taddress";
			for(int i=0;i<n;i++)
			{
				cout<<"\n"<<hash[i].name<<"\t";
				cout<<hash[i].telephone<<"\t";
				cout<<hash[i].addr<<"\t";
			}
	}

	void quadratic()
	{
					long int telephone;
					string name;
					string addr;
					cout<<"\n enter name:";
					cin>>name;
					cout<<"\n enter Tel no:";
					cin>>telephone;
					cout<<"\n enter address:";
					cin>>addr;
					int pos;
					pos=(telephone)%n;
					for(int i=0;i<n;i++)
					{
						if(flag[pos]==0)
						{
							hash[pos].telephone=telephone;
							hash[pos].addr=addr;
							hash[pos].name=name;
							cout<<"\n done ";
							flag[pos]=1;
							return;
						}
						pos=(pos+(i*i))%n;
					}
					cout<<"\n not found....!!!!";
					return;
	}
	void quadratic_search()
			{
				long int telephone;
				int pos;
				cout<<"\n enter telephone :";
				cin>>telephone;
				pos=(telephone)%n;
				for(int i=0;i<n;i++)
				{
					if(hash[pos].telephone ==telephone)
					{
						cout<<"\n found .....!!";
						cout<<"\n"<<hash[pos].name<<"\t";
						cout<<hash[pos].telephone<<"\t";
						cout<<hash[pos].addr<<"\t";
						return;
					}
					pos=(pos+(i*i))%n;
				}
				cout<<"\n element not found....!!!";
				return;
			}
	void linear_chain()
		{

			string name,addr;
			long int telephone;
			int pos=0;
			cout<<"\nEnter name: ";
			cin>>name;
			cout<<"\nEnter telephone number: ";
			cin>>telephone;
			cout<<"\nEnter address: ";
			cin>>addr;
			int i=0;
			pos=(telephone)%n;

			while(flag[i]==1 && i<n)
			{
				if(hash[pos].telephone%n == telephone%n)
				{

					break;
				}

				i++;
				pos=(pos+1)%n;
			}

			while(chain[pos]!=-1)
			{
				pos=chain[pos];

			}
			int j=pos;

			while(flag[j]==1 && i<n)
			{
				j=(j+1)%n;
				i++;
			}
			if(i==n)
			{
				cout<<"\n table is full::";
				return;
			}
					hash[j].telephone=telephone;
					hash[j].name=name;
					hash[j].addr=addr;
					flag[j]=1;
					if(j!=pos)
					{
					chain[pos]=j;

					return ;
					j=chain[j];
					}

					return;
		}

		void search_chain()
		{
			long int telephone;
							int pos;
							cout<<"\n enter telephone :";
							cin>>telephone;
							pos=(telephone)%n;
							int i=0;
							if(flag[pos]==1 && hash[pos].telephone==telephone)
							{
								cout<<"\n data found...!!";
								cout<<"\n"<<hash[pos].name<<"\t";
								cout<<hash[pos].telephone<<"\t";
								cout<<hash[pos].addr<<"\t";
								return;
							}
							if(flag[pos]==1 && hash[pos].telephone%n == telephone%n && flag[pos]==1 && hash[pos].telephone!=telephone )
							{
								while(chain[pos]!=-1)
								{
									if(flag[pos]==1 && hash[pos].telephone==telephone)
																{
																	cout<<"\n data found...!!";
																	cout<<"\n"<<hash[pos].name<<"\t";
																	cout<<hash[pos].telephone<<"\t";
																	cout<<hash[pos].addr<<"\t";
																	return;
																}else
																{
																	pos=chain[pos];
																}
								}
								if(flag[pos]==1 && hash[pos].telephone==telephone)
								{
									cout<<"\n data found...!!";
									cout<<"\n"<<hash[pos].name<<"\t";
									cout<<hash[pos].telephone<<"\t";
									cout<<hash[pos].addr<<"\t";
									return;
								}else
								{
									cout<<"\n not present..!!";
									return ;
								}

							}

		}


};
int main()
{
	hash1 h,h1;
	int c,ch;
	do
	{
		cout<<"\n1. linear probing :";
		cout<<"\n2.	quadratic probing:";
		cout<<"\n3.	linear prob chaining:";
		cout<<"\n more operation..";
		cin>>ch;
		switch(ch)
		{
		case 1:
				{
					do
					{
						cout<<"\n1. linear probing without replacent insertion:";
						cout<<"\n2.	dipslay";
						cout<<"\n3.	search in linear probing:";
						cin>>ch;
						switch(ch)
						{
						case 1:h.linear_prob_without_repl();
								break;
						case 2:h.disp();
								break;
						case 3:h.search_linear_prob_without_repl();
								break;
						}
						cout<<"\n more operarion on linear probing..";
						cin>>c;
					}while(c==1);
						break;
				}
		case 2:
				{
					do
					{
						cout<<"\n1. quadratic probing without replacent insertion:";
						cout<<"\n2.	dipslay";
						cout<<"\n3.	search in quadratic probing:";
						cin>>ch;
						switch(ch)
						{
						case 1:h.quadratic();
								break;
						case 2:h.disp();
								break;
						case 3:h.quadratic_search();
								break;
						}
						cout<<"\n more operarion on quadratic probing..";
						cin>>c;
					}while(c==1);
				break;
				}
		case 3 :
		{

			do
			{
				cout<<"\n1. linear probing with chaining insertion:";
				cout<<"\n2.	dipslay";
				cout<<"\n3.	search in linear chaining probing:";
				cin>>ch;
				switch(ch)
				{
				case 1:h1.linear_chain();
						break;
				case 2:h1.disp();
						break;
				case 3:h1.search_chain();
						break;
				}
				cout<<"\n more operarion on quadratic probing..";
				cin>>c;
			}while(c==1);
		break;

		}
				cout<<"\n more operation";
				cin>>c;
		}
	}while(c==1);

	return 0;
}
