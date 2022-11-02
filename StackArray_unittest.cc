#include <gtest/gtest.h>
#include "StackArray.h"

namespace{

  const int size = 5;

  TEST(StackArray, Constructor) {
    const StackArray<char> myStack(size);
    EXPECT_EQ(myStack.getSize(), size);
    EXPECT_EQ(myStack.getData() != nullptr, true);
    EXPECT_EQ((int)(sizeof(myStack.getData()) / sizeof(*myStack.getData())), size);
    EXPECT_EQ(myStack.getData(), myStack.getStackPointer());
  }

  TEST(StackArray, isEmpty) {
    const StackArray<char> myStack(size);
    EXPECT_EQ(myStack.getStackPointer() - myStack.getData(), 0);
    myStack.push('a');
    EXPECT_EQ(myStack.getStackPointer() - myStack.getData(), 1);
  }

  TEST(StackArray, push) {
    const StackArray<char> myStack(size);
    myStack.push('a');
    myStack.push('b');
    myStack.push('c');
    myStack.push('d');
    myStack.push('e');
    EXPECT_EQ(myStack.getSize(), 5);
    myStack.push('f');
    EXPECT_EQ(myStack.getSize(), 5 + RESIZE_FACTOR);
  }

  TEST(StackArray, pop) {
    const StackArray<char> myStack(size);
    EXPECT_EQ(myStack.isEmpty(), myStack.getStackPointer() == myStack.getData());
    EXPECT_EQ(!myStack.isEmpty(), myStack.getStackPointer() - myStack.getData() == 1);
  }
  
  TEST(StackArray, top) {
    const StackArray<char> myStack(size);
    myStack.push('a');
    EXPECT_EQ(myStack.top(), 'a');
  }
}