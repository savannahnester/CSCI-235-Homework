/*
Savannah Nester
CSCI 235 Programming Assignment 2 Question 2
Implement a MyQueue class which implements a queue using two stacks.
*/
#include<iostream>
#include<stack>
using namespace std;

template <class T>
class MyQueue {
  stack<T> main; //main stack to hold values
  stack<T> temp; //second temporary stack

public:
  T front(){
    return main.top(); //get top of main stack
  }
  void push(T value){
    //push a new value into the bottom of the stack
    //then move all elements from the main stack into the temp stack
    while(!main.empty()){
      temp.push(main.top());
      main.pop();
    }
    main.push(value);
    //push value into the bottom of main stack
    //then move back all values in temp stack into the main stack
    while(!temp.empty()){
      main.push(temp.top());
      temp.pop();
    }
  }
  T pop(){
    //pop the top of the stack
    T temp_ = main.top();
    main.pop();
    return temp_;
  }
  bool empty(){
    //check if main stack is empty and return true or false
    return main.empty();
  }
};
int main(){
  MyQueue<int> q;
  int num;
  //using int values to test class though any type can be used since
  //created a template class T
  for(int i = 0; i < 5; i++){
    //populate the stack with 5 numbers for testing purposes
    cout << "Enter a number: ";
    cin >> num;
    q.push(num);
  }
  while(!q.empty()){
    cout << q.pop() << " ";
  }
  cout << endl;
  return 0;
}
