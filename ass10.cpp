/*
Assignment No:: 10
Title :: A business house has several offices in different countries; they want to lease phone lines to
	connect them with each other and the phone company charges different rent to connect
	different pairs of cities. Business house want to connect all its offices with a minimum total
	cost. Solve the problem by suggesting appropriate data structures(by prims Algo)

*/
/*---CODE---*/
#include<iostream>
#include<stdlib.h>
#define INF 9999
#define MAX 100
using namespace std;

class graph
{
	int n,edges;
	int g[MAX][MAX];
	
      public:
      		graph()
      		{
      		}
      		void readg()
      		{
      			int i,j,e,weight;
      			cout<<"\nEnter Number of Contries::";
      			cin>>n;
      			for(i=0;i<n;i++)
      			{
      				for(j=0;j<n;j++)
      				{
      					if(i==j)
      					{
      						g[i][j]=0;
      					}
      					else
      					{
      						g[i][j]=INF;
      					}
      				}
      			}
      			cout<<"Enter No of Connection::";
      			cin>>edges;
      			cout<<"Enter Source and Destion Country and Distance::(first country is 0 eg. 0 1 3)";
      			for(e=0;e<edges;e++)
      			{
      				cin>>i;
      				cin>>j;
      				cin>>weight;
      				g[i][j]=weight;
      				g[j][i]=weight;
      			}
      		}
      		void prims()
      		{
      			int pass,min,temp;
      			int sum=0;
      			int visited[MAX];
      			int l,m,k;
      			for(int i=0;i<n;i++)
      			{
      				visited[i]=0;
      			}
      			visited[0]=1;
      			cout<<"\nMinimum Distance Connection is::";
      			for(pass=0;pass<n-1;pass++)
      			{
      			
      				min=999;
      				for(int i=0;i<n;i++)
      				{
      					temp=999;
      					if(visited[i]==1)
      					{
      						for(int j=0;j<n;j++)
      						{
      							if(g[i][j]<temp && visited[j]==0)
      							{
      								temp=g[i][j];
      								k=j;
      							}
      						}	
      					}
      					if(min>temp)
      					{
      						min=temp;
      						l=i;
      						m=k;
      					}
      				}
      			sum=sum+min;
      			visited[l]=1;
      			visited[m]=1;
      			cout<<"\nSource Country\t"<<l<<" to "<<m<<"\tDistination Contry ::"<<min;
      			}
      		cout<<"\nDistance is::"<<sum;
      		}
};

int main()
{
	graph g1;
	g1.readg();
	g1.prims();
	return 0;
}
/*---Output---/
/*

*/
