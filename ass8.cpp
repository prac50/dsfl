#include<iostream>
#include<stdlib.h>
using namespace std;
#define MAX 20
#define INFINITY 999

class graph
{
	int edges,nodes,sv,wt[MAX][MAX];
	bool visited[MAX];
	int predec[MAX];
	int dist[MAX];
	public:
	graph(int,int);
	void create_graph();
	void disp_adj_matrix();
	void node_init();
	int get_closest_node();
	void shortest_path();
	void output();
	void printpath(int node);
};

graph::graph(int n, int e)
{
	int i,j;
	nodes=n;
	edges=e;
	for(i=0;i<nodes;i++)
	{
		for(j=0;j<nodes;j++)
		{	
			if(i==j)
				wt[i][j]=0;
			else
				wt[i][j]=INFINITY;
		}
	}
}

void graph::create_graph()
{
	int i,startnode,endnode,woe;
	for(i=0;i<edges;i++)
	{
		cout<<"Enter start node, end node and weight of edge:";
		cin>>startnode>>endnode>>woe;
		wt[startnode][endnode]=woe;
	}
	do
	{
		cout<<"Enter source vertex:";cin>>sv;
		if(sv<0||sv>(nodes-1))
			cout<<"Invalid vertex!!Enter other value for source!!";
			
	}while(sv<0||sv>(nodes-1));
}

void graph::disp_adj_matrix()
{
	int i,j;
	for(i=0;i<nodes;i++)
	{
		cout<<"\n";
		for(j=0;j<nodes;j++)
		{
			cout<<wt[i][j]<<" ";
		}
	}
	cout<<endl;
}

void graph::node_init()
{
	int i;
	for(i=0;i<nodes;i++)
	{
		visited[i]=false;
		predec[i]=-1;
		dist[i]=INFINITY;
	}
	dist[sv]=0;
}

int graph::get_closest_node()
{
	int mind=INFINITY,cn;
	for(int i=0;i<nodes;i++)
	{
		if(!visited[i]&&(mind>dist[i]))
		{
			mind=dist[i];
			cn=i;
		}
	}
	return cn;
}

void graph::shortest_path()
{
	int i,j;
	node_init();
	for(i=0;i<nodes-1;i++)
	{
		int cn=get_closest_node();
		visited[cn]=true;
		for(j=0;j<nodes;j++)
		{
			if(!visited[j]&&(wt[cn][j]>0))
			{
				if(dist[j]>dist[cn]+wt[cn][j])
				{
					dist[j]=dist[cn]+wt[cn][j];
					predec[j]=cn;
				}
			}
		}
		
	}
}

void graph::output()
{
	for(int i=0;i<nodes;i++)
	{
		if(i==sv)
			cout<<endl<<sv<<"_"<<sv;
		else
			printpath(i);
		cout<<"==>"<<dist[i];
	}
}

void graph::printpath(int node)
{
	if(node==sv)
		cout<<"\nnode"<<"_";
	else if(predec[node]==-1)
		cout<<"\nNo path from "<<sv<<" to "<<node;
	else
		printpath(predec[node]);
		cout<<node<<"_";
}

int main()
{
	cout<<"\t\t***Shortest Path by Djikstra's Algorithm***\n\n";
	int n,e;
	cout<<"Enter number of nodes:";cin>>n;
	cout<<"Enter number of edges:";cin>>e;
	graph g(n,e);
	g.create_graph();
	g.disp_adj_matrix();
	g.shortest_path();
	g.output();
	cout<<endl;
}
