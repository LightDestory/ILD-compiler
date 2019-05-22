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
};

#endif
