/*
Savannah Nester
CSCI 235 Programming Assignment 3 Question 4
Given is a weighted connected undirected graph. Write a program to find the spanning tree of this graph
with minimum total weight.
Spanning tree: a spanning tree T of an undirected graph G is a subgraph that is a tree which includes
all of the vertices of G.
Tree: is a connected graph which has no cycle.
*/
#include<iostream>
#include<stdlib.h>
#define inf 999
using namespace std;

class prims
{
public:
  int g[20][20];
  int n;
  int e;
  void initmat();
  void display();
  void create();
  void primsmat();

};
//initlize all values to infinity value
void prims::initmat()
{
  int i,j;
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      g[i][j]=inf;
    }
  }
}
//get values for vertices, edges, and populate using user input
void prims::create() {
  int i,u,v,w;
  cout<<"\nEnter the number of vertices: ";
  cin>>n;
  cout<<"\n Enter the number of edges: ";
  cin>>e;
  initmat();
  for(i=0;i<e;i++)
  {
    cout<<"\nEnter the edge "<<i+1 << " ";
    cin>>u>>v>>w;
    g[u][v]=g[v][u]=w;
  }
}

void prims::display()
{
  int i,j;
  for(i=0;i<n;i++)
  {
    cout<<"\n";
    for(j=0;j<n;j++)
    {
      cout<<"\t"<<g[i][j];
    }
  }
}
//find mimimum spanning tree using Prim's MST
void prims::primsmat()
{
  int visited[10],dist[10],from[10];
  int min,u,v,sv,i,j;
  //source vertex
  cout<<"\nEnter the starting vertex: ";
  cin>>u;
  sv=u;
  //mark as visited
  for(v=0;v<n;v++)
  {
    visited[v]=0;
    from[v]=u;
    dist[v]=g[u][v];
  }
  visited[u]=1;

  for(i=1;i<n-1;i++)
  {
    //initialize min to inf
    min=inf;
    for(v=0;v<n;v++)
    {
      //update value of min
      if(dist[v]<min&&!visited[v])
      {
        min=dist[v];
        u=v;
      }
    }
    visited[u]=1;
    //find minimum edge weights
    for(v=0;v<n;v++)
    {
      if((min+g[u][v])<dist[v]&&!visited[v])
      {
        dist[v]=min+g[u][v];
        from[v]=u;
      }
    }

  }
  for(i=0;i<n;i++)
  {
    if(i!=sv)
    {
      //print the path
      cout<<"\nPath: "<<i;
      j=i;
      do
      {
        j=from[j];
        cout<<j;

      }
      //output distance
      while(j!=sv);
      cout<< "Distance is "<<dist[i];
    }
  }
}
//main function
int main()
{
  prims p;
  system("clear");
  cout<<"Adjacency Matrix";
  p.create();
  cout<<" created successfully";
  p.display();
  p.primsmat();

  return 0;
}
