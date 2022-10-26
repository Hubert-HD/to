#include <iostream>     
#include <cassert>
#include "StackArray.cc"

int main(){
  StackArray<char> myStack(5);
  myStack.push('a');
  std::cout << myStack.top();
  myStack.pop();
  std::cout << myStack.top();
  std::cout << myStack.isEmpty();
  return 0;
}