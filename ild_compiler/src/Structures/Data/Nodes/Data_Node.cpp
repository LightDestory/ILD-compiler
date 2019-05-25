#include "Data_Node.h"
#include<iostream>

using namespace std;
using namespace Data;

Data_Node::Data_Node(string _label, int _value, unsigned int _index, string _encode, bool _is_array) {
    label = _label;
    value = _value;
    index = _index;
    encode = _encode;
    is_array = _is_array;
}

void Data_Node::setEncode(string _encode) { encode = _encode; }

string Data_Node::getEncode() const { return encode; }

void Data_Node::setValue(int _value) { value = _value; }

int Data_Node::getValue() const { return value; }

string Data_Node::getLabel() const { return label; }

unsigned int Data_Node::getIndex() const { return index; }

bool Data_Node::isArray() const { return is_array; }