
#include<iostream>

using namespace std;

class kruskal

{

struct node

{

int a,b;

int weight;

};

 
//path to save the edges information in MST

//store to save the edges information in the original graph

struct node store[100],path[100];


int parent[100]; //array to store parents of the vertices

int n,pn,nv,ne;

public:

kruskal()

{

for(int x = 0;x<100;x++)

{

parent[x] = x;

 

}

n = 0;pn = 0;

}

void kAlgo()

{

sort();pn = 0;int x = 0;

 

while(pn<nv-1)

{

int p1 = find(store[x].a);

int p2 = find(store[x].b);

 

if(p1!=p2)

{

path[pn++] = store[x];

unionC(p1,p2);

}

x++;

}

}


void displayPath()

{

cout<<"\n\n"<<endl;

int cost = 0;

for(int x = 0;x<pn;x++)

{

cout<<path[x].a<<" - "<<path[x].b;

cout<<"\tw = "<<path[x].weight<<endl;

cost += path[x].weight;

}

cout<<"Cost = "<<cost<<endl;

}

 

void create()

{

n = 0;

cout<<"Enter number of vertices = ";

cin>>nv;

cout<<"Enter number of edges = ";

cin>>ne;

cout<<"Enter edge information: vertex A vertex B weight";

 

for(int i=0;i<ne;i++){

cin>>store[i].a>>store[i].b>>store[i].weight;

}

}

 

void display()

{

for(int x = 0;x<ne;x++)

{

cout<<store[x].a<<" - "<<store[x].b<<endl;

cout<<"Weight = "<<store[x].weight<<"\n"<<endl;

}

}

 

 

void sort()

{

for(int x = 1;x<ne;x++)

{

for(int y = 0;y<ne-x;y++)

{

if(store[y+1].weight<store[y].weight)

{

struct node temp = store[y+1];

store[y+1] = store[y];

store[y] = temp;

}

}

 

}

}

 

 

 

 

void unionC(int i,int j)

{

parent[j] = i;

}

 

 

int find(int x)

{

if(parent[x]!=x)

{

parent[x] = find(parent[x]);

}

return parent[x];

}

 

 

 

};

 

 

int main()

{

kruskal k;

int ch;

do

{

cout<<"\n1 - To create graph\n2 - Display Graph\n3 - Fint MST\n4 - Display path and cost"<<endl;

cout<<"Enter Choice"<<endl;

cin>>ch;

switch(ch)

{

case 1: k.create();

break;

 

case 2: k.display();

break;

 

case 3: k.kAlgo();

cout<<"Calculation Successful"<<endl;

break;

 

case 4: k.displayPath();

break;

 

case 5: cout<<"Thanks"<<endl;

break;

 

default: cout<<"Wrong Option"<<endl;

}

}while(ch!=5);

}

