#include "StackArray.h"
#include <cassert>

template <typename T> StackArray<T>::StackArray(int sz){
  assert(sz > 0);
  size = sz;
  data = new T[size];
  stackPointer = data;
};

template <typename T> bool StackArray<T>::isEmpty(){
  bool isEmpty = stackPointer == data;
  assert((stackPointer - data == 0) == (isEmpty == true));
  assert((stackPointer - data > 0) == (isEmpty == false));
  return isEmpty;
}

template <typename T> void StackArray<T>::push(T element){
  int stackSize = stackPointer - data;
  if(stackSize == size)
    resize();
  *stackPointer = element;
  stackPointer++;
}

template <typename T> void StackArray<T>::pop(){
  int oldSize = stackPointer - data;
  if(!isEmpty()) 
    stackPointer--;
  assert((oldSize == 0) == (stackPointer - data == oldSize));
  assert((oldSize > 0) == (stackPointer - data == oldSize - 1));
}

template <typename T> T StackArray<T>::top(){
  T top;
  if(!isEmpty()) 
    top = *(stackPointer - 1);
  assert((stackPointer - data == 0) == (top != *(stackPointer - 1)));
  assert((stackPointer - data > 0) == (top == *(stackPointer - 1)));
  return top;
}

template <typename T> void StackArray<T>::resize(){
  size += RESIZE_FACTOR;
  T* newData = new T[size];
  for (int i = 0; i < size; i++)
    newData[i] = data[i];
  delete data;
  data = newData;
  stackPointer = newData + size;
}

template <typename T> StackArray<T>::~StackArray(){
  delete data;
};