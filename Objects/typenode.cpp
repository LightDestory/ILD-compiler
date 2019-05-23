#include <iostream>
#include "typenode.h"
using namespace std;

Node::Node(string _label, int _value, int _index, string _encode){
      Node::label = _label;
      Node::value = _value;
      Node::index = _index;
      Node::encode = _encode;
}

int Node::getIndex() { return Node::index; }
int Node::getValue() { return Node::value; }
string Node::getLabel() { return Node::label; }
string Node::getEncode() { return Node::encode; }

void Node::setValue( int _value ) { Node::value = _value; }
void Node::setEncode ( string _encode ) { Node::encode = _encode; }

Node& Node::operator=(Node& nd) {
  Node::label = nd.getLabel();
  Node::value = nd.getValue();
  Node::index = nd.getIndex();
  Node::encode = nd.getEncode();
}

Stack::Stack(int _stack_max) {
  Stack::stack_max = _stack_max;
  Stack::nodes = new Node*[stack_max];
  Stack::stack_pop = 0;
}

void Stack::init(int i, string label, int value, int index, string encode) {
  if(i >= Stack::stack_max) return;
  Stack::nodes[i] = new Node(label, value, index, encode);
}

Node* Stack::operator[](int i) {
  if(i < Stack::stack_max)
    return Stack::nodes[i];
  return NULL;
}
