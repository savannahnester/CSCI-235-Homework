/*
Savannah Nester
CSCI 235 Programming Assignment 3 Question 3
Write a program to find minimum weight cycle in an undirected weighted graph.
The input is the Adjacency Matrix A of the graph. If there is an edge between vertex i to vertex j, and
weight of this edge is w, then A[i; j] = A[j; i] = w. If there is no edge between i and j, A[i; j] = A[j; i] = 􀀀1.
*/
#include<iostream>
#include<list>
#include<utility>
#include<functional>
#include<vector>
#include<set>
using namespace std;

#define INFVALUE 0x3f3f3f3f

struct edgeDetail
{
  int sv;
  int dv;
  int weight;
};
//undreicted graph class
class udGraph
{
  int vertex;
  //declare the adjacent in list
  list <pair <int, int> >*A;
  //vector to store edge details
  vector <edgeDetail> ed;
public:
//constructor for udGraph
  udGraph(int vertex)
  {
    this->vertex = vertex;
    A = new list <pair<int, int> >[vertex];
  }
  void insertEdge(int sv, int dv, int w);
  void deleteEdge(int sv, int dv, int w);
  int computeMinimumPath(int sv, int dv);
  void deleteEdge(int sv, int dv);
  int computeMinimumCycle();
};
//insert edge into UDGraph
void udGraph :: insertEdge(int sv, int dv, int w1)
{
  A[sv].push_back(make_pair(dv, w1));
  A[dv].push_back(make_pair(sv, w1));
  //insert edge to given edge list
  edgeDetail e1;
  e1.sv = sv;
  e1.dv = dv;
  e1.weight =  w1;
  ed.push_back (e1);
}
//delete edge
void udGraph :: deleteEdge(int sv, int dv, int w1)
{
  //deleting the edge
  A[sv].remove(make_pair(dv, w1));
  A[dv].remove(make_pair(sv, w1));
}
//use Dijkstra's algorithm to compute minimum path
int udGraph::computeMinimumPath(int sv, int dv)
{
  set<pair<int, int> > s;
  //distance vector
  //initializes the infinity for every distance
  vector<int> d(vertex, INFVALUE);
  //insert source
  s.insert(make_pair(0, sv));
  d[sv] = 0;
  while (!s.empty())
  {
    pair<int, int> t = *(s.begin());
    s.erase(s.begin());
    int sv = t.second;
    list< pair<int, int> >::iterator it;
    for (it = A[sv].begin(); it != A[sv].end(); ++it)
    {
      int dv = (*it).first;
      int weight = (*it).second;
      //If there is minimum path to dv by su
      if (d[dv] > d[sv] + weight)
      {
        //make sure it's not infinity value
        if (d[dv] != INFVALUE)
        s.erase(s.find(make_pair(d[dv], dv)));
        //alter the distance of dv
        d[dv] = d[sv] + weight;
        s.insert(make_pair(d[dv], dv));
      }
    }
  }
  //return shortest path
  return d[dv];
}

int udGraph :: computeMinimumCycle()
{

  int mc = INT_MAX;
  int te = ed.size();
  for (int r = 0 ; r < te ; r++)
  {
    edgeDetail e = ed[r];
    deleteEdge(e.sv, e.dv, e.weight);
    //compute minimum distance between 2 vertices
    int md = computeMinimumPath(e.sv, e.dv);
    //compute minimum cycle value
    mc = min(mc, md + e.weight );
    //call insertEdge()
    insertEdge(e.sv, e.dv, e.weight );
  }
  return mc ;
}
//use main for testing
int main()
{
  int totalVertex = 9;
  //create object for undirected graph
  udGraph adj(totalVertex);
  //make graph
  adj.insertEdge(2, 3, 5);
  adj.insertEdge(1, 3, 2);
  adj.insertEdge(0, 2, 4);
  adj.insertEdge(0, 1, 1);
  adj.insertEdge(0, 3, 3);
  cout << "Minimum cycle value: "<<adj.computeMinimumCycle() << endl;
  return 0;
}
