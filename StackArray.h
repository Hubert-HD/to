#include "Stack.h"

#ifndef STACK_ARRAY_H
#define STACK_ARRAY_H
#define RESIZE_FACTOR 20

template <typename T> 
class StackArray: public Stack<T>{
  private:
    T* data;
    int size;
    T* stackPointer;
    void resize();

  public:
    StackArray(int);
    void push(T);
    void pop();
    T top(); 
    bool isEmpty();
    ~StackArray();
};

#endif