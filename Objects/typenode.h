#ifndef __TNODE_H__
#define __TNODE_H__

#include <iostream>
using namespace std;

class Node {

private:
  unsigned int index, value;
  string label, encode;

public:

  Node(string _label, int _value, int _index, string _encode);

  void setEncode (string _encode);
  void setValue(int _value);

  string getEncode();
  string getLabel();
  int getIndex();
  int getValue();
  Node& operator=(Node& nd);

};

class Stack {

private:

  Node** nodes;
  int stack_pop, stack_max;


public:

  Stack(int _stack_max);
  void init(int i, string label, int value, int index, string encode);
  Node* operator[](int i);

};

#endif
