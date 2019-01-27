/*
Savannah Nester
CSCI 235 Programming Assignment 2 Question 1
Write a program to sort a stack such that the smallest items are on the top. You can use an additional
temporary stack, but you may not copy the elements into any other data structure (such as an array).
The stack supports the following operations: push, pop, peek, and is Empty.
*/
#include<iostream>
#include<stack>
using namespace std;
stack<int> sort(stack<int> &input){
  stack<int> temporaryStack;
  while (!input.empty()){
    //pop first element in stack
    int temp = input.top();
    input.pop();
    //while temporary stack isn't empty and top of stack is less than temp
    while(!temporaryStack.empty() && temporaryStack.top() < temp){
      //pop from temporaryStack and push it to input stack
      input.push(temporaryStack.top());
      temporaryStack.pop();
    }
    //push temp in temporaryStack
    temporaryStack.push(temp);
  }
  return temporaryStack;
}
int main(){
  stack<int> input;
  int num;
  //test with 6 numbers taken from user input for input stack
  for(int i = 0; i < 6; i++){
    cout << "Enter a number: " << endl;
    cin >> num;
    input.push(num);
  }
  //this is the temporary stack
  stack<int> temporaryStack_ = sort(input);
  cout << "Sorted numbers are: " << endl;
  while(!temporaryStack_.empty()){
    cout << temporaryStack_.top() << " ";
    temporaryStack_.pop();
  }
  cout << endl;
  return 0;
}
