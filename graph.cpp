#include<iostream>
#include<stack>
#include<queue>
using namespace std;
class graph1
{
int a[4][4],n=4;
public:
	graph1()
	{
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				a[i][j]=0;
	}

	void acc()
	{
		int c;
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				cout<<"\n age between "<<i<<"and"<<j;
				cin>>c;
				if(c==0)
				{
					a[i][j]=a[j][i]=0;
				}else
				{
					a[i][j]=a[j][i]=1;
				}
			}
		}
	}
	void disp()
	{
		for(int i=0;i<n;i++)
		{
					for(int j=0;j<n;j++)
					{
						cout<<a[i][j];
					}cout<<"\n";
		}
		}

	void DFS()
	{
		stack<int>st;
		int x,visit[10];
		for(int i=0;i<n;i++)
		{
			visit[i]=0;
		}
		st.push(0);
		visit[0]=1;
		while(!st.empty())
		{
			int x;
			x=st.top();
			st.pop();
			cout<<x;
			for(int i=0;i<n;i++)
			{
				if(a[i][x]!=0 && visit[i]==0)
				{
					st.push(i);
					visit[i]=1;
				}
			}
		}
	}

	void BFS()
	{
		queue<int>st;
		int x,visit[10];
		for(int i=0;i<n;i++)
		{
			visit[i]=0;
		}
		st.push(0);
		visit[0]=1;
		while(!st.empty())
		{
			int x;
			x=st.front();
			st.pop();
			cout<<x;
			for(int i=0;i<n;i++)
			{
				if(a[i][x]!=0 && visit[i]==0)
				{
					st.push(i);
					visit[i]=1;
				}
			}
		}
	}

};

struct node
{
	int data;
	node * next;

};

class graph2
{
node *hn[10],*tail[10];
int n,v,e;
public:
		graph2()
		{
			cout<<"\n enter no of vertices:";
			cin>>v;
			cout<<"no of edges:";
			cin>>e;
			for(int i=0;i<10;i++)
			{
				hn[i]=NULL;
			}
		}

		void acc()
		{
			int c;
			int i=0;
			node *nn;
				while(i<e)
				{
				int v1,v2;
				cout<<"\n enter edge:;";
				cin>>v1>>v2;
				nn=new node();
				nn->next=NULL;
				nn->data=v2;
				if(hn[v1]==NULL)
				{
					hn[v1]=nn;
					tail[v1]=nn;
				}else
				{
					tail[v1]->next=nn;
					tail[v1]=nn;
				}

				nn=new node();
						nn->next=NULL;
						nn->data=v1;
						if(hn[v2]==NULL)
						{
							hn[v2]=nn;
							tail[v2]=nn;
						}else
						{
							tail[v2]->next=nn;
							tail[v2]=nn;
						}

				i++;
				}
		}

		void DFS()
					{
					int visite[10];
					node *cn;
						for(int i=0;i<10;i++)
						{
							visite[i]=0;
						}

					    stack <node *> q;
						int n;
						cout<<"\n starting vert::";
						cin>>n;
						visite[n]=1;
						q.push(hn[n]);
						cout<<"\t "<<n;
						while(!q.empty())
						{
							cn=q.top();
							//cout<<"\n front:"<<cn->data;
							q.pop();
							cout<<"\t"<<cn->data;
							visite[cn->data]=1;
							cn=hn[cn->data];
							while(cn!=NULL)
							{
								if(visite[cn->data]==0 )
									{
										visite[cn->data]=1;
										q.push(cn);
									}
									cn=cn->next;
							}
						}

					}


		void BFS()
					{
					int visite[10];
					node *cn;
						for(int i=0;i<10;i++)
						{
							visite[i]=0;
						}

					    queue <node *> q;
						int n;
						cout<<"\n starting vert::";
						cin>>n;
						visite[n]=1;
						q.push(hn[n]);
						cout<<"\t "<<n;
						while(!q.empty())
						{
							cn=q.front();
							//cout<<"\n front:"<<cn->data;
							q.pop();
							cout<<"\t"<<cn->data;
							visite[cn->data]=1;
							cn=hn[cn->data];
							while(cn!=NULL)
							{
								if(visite[cn->data]==0 )
									{
										visite[cn->data]=1;
										q.push(cn);
									}
									cn=cn->next;
							}
						}

					}
};
int main()
{
	graph2 g;
	/*
	 * g.acc();
	g.disp();
	cout<<"\n DFS";
	g.DFS();
	cout<<"\n BFS";
	g.BFS();
	 *
	 */
	g.acc();
	cout<<"\n DFS::";
	g.DFS();
	cout<<"\n BFS:";
	g.BFS();
	return 0;
}
