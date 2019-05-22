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
