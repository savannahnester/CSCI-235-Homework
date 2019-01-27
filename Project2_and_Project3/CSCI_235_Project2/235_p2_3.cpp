/*
Savannah Nester
CSCI 235 Programming Assignment 2 Question 3
Given a circular linked list, implement an algorithm that returns the node at the beginning of the loop.
Denition: Circular linked list: A (corrupt) linked list in which a node's next pointer points to an earlier
node, so as to make a loop in the linked list.
*/
#include<iostream>
#include<cstdlib>
using namespace std;

int Append(struct node **q, char data);
char FindStartOfNode(struct node **q);

struct node{
  char data;
  struct node *link;
};
//this function finds the beginning node in the linked list
char FindStartOfNode(struct node **q){
  struct node *r, *t;
  r = *q;
  t = *q;

  //loop through list
  while(t->link != NULL){
    r = r->link;
    t = t->link->link;
    //exit loop if r and t are equal
    if(r == t){
      break;
    }
  }
  //return null if t is null
  if(t == NULL)
    return '\0';
  r = *q;
  while(r != t){
    t = t->link;
    r = r->link;
  }
  return t->data;
}

int main(){
  struct node *p;
  p = NULL;
  char letter;
  //testing for letters in example: A, B, C, D, E, C
  Append(&p, 'A');
  Append(&p, 'B');
  Append(&p, 'C');
  Append(&p, 'D');
  Append(&p, 'E');
  Append(&p, 'C');
  letter = FindStartOfNode(&p);
  cout << " Output: " << letter << endl;
  return 0;
}

int Append(struct node **q, char data){
  struct node *r, *t, *start_of_cycle = NULL;
  r = (struct node *)malloc(sizeof(struct node));

  r->data = data;

  r->link = NULL;

  if(*q == NULL)
    *q = r;
  else {
    t = *q;
    while(t->link != NULL){
      if(t->data == data)
        start_of_cycle = t;
      t = t->link;
    }
    if(start_of_cycle == NULL)
      t->link = r;
    else{
      //otherwise there is a cycle in the linked list
      t->link = start_of_cycle;
      free(r);
    }
  }
  return 0;
}
