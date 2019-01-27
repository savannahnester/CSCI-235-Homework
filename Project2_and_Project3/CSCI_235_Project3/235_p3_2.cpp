/*
Savannah Nester
CSCI 235 Programming Assignment 3 Question 2
Write a program to nd all Strongly Connected Components of a directed graph.
The input is the Adjacency Matrix A of the graph. If there is an edge from vertex i to vertex j, A[i; j] = 1
and A[j; i] = 􀀀1. If there is no edge between i and j, A[i; j] = A[j; i] = 0.
*/
#include <iostream>
#include <list>
#include <stack>
using namespace std;

#define N 5

void DFS(int v, bool visited[], int A[N][N]){
//current node = visited
visited[v] = true;
cout << v << " ";
//check if adjacent vertices are visited or not
for(int i=0;i<N;i++){
  if(A[v][i]==1){
      if(!visited[i]){
          DFS(i,visited,A);
        }
      }
    }
}

void getTranspose(int A[N][N]){
//iterate through all vertices in 2D array and transpose it (switch rows/columns)
for(int i=0;i<N;i++){
  for(int j=i+1;j<N;j++){
      if(A[i][j]==1){
          A[i][j] = -1;
          A[j][i] = 1;
        }
        else if(A[i][j]==-1){
          A[i][j] = 1;
          A[j][i] = -1;
        }
    }
  }
}

void fillOrder(int v, bool visited[], stack<int> &Stack, int A[N][N]){
///mark current node as visisted
visited[v] = true;
//Recursively check if adjacent matrices are visited, if not recur
for(int i=0;i<N;i++){
  if(A[v][i]==1){
      if(!visited[i]){
          fillOrder(i, visited, Stack,A);
        }
      }
    }
Stack.push(v);
}

//get the strongly connected components (SCC for short)
void SCC(int A[N][N]){
stack<int> Stack;
//mark every vertex as unvisited
bool *visited = new bool[N];
for(int i = 0; i < N; i++)
  visited[i] = false;
//fill vertices based on finishing times
for(int i = 0; i < N; i++){
  if(visited[i] == false)
    fillOrder(i, visited, Stack, A);
}
//reverse graph
getTranspose(A);
//iterate and mark as not visited
for(int i = 0; i < N; i++)
  visited[i] = false;

while (!Stack.empty()){
  //v = top of stack
  int v = Stack.top();
  //pop element
  Stack.pop();
  if (visited[v] == false){
    //print SCC of removed vertex
    DFS(v, visited,A);
    cout << endl;
  }
 }
}

//main function for testing purposes
int main(){
int A[N][N] = {0};
A[0][2] = 1;A[2][0] = -1;
A[2][1] = 1;A[1][2] = -1;
A[1][0] = 1;A[0][1] = -1;
A[0][3] = 1;A[3][0] = -1;
A[3][4] = 1;A[4][3] = -1;

cout << "The strongly connected components of the graph are: " << endl;
SCC(A);

return 0;
}
