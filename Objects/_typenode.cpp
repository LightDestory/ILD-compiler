#include <iostream>
using namespace std;

class Node{
  private:
    unsigned int index, value;
    string label, encode;
    //Node *prev, *next;

  public:
    Node(string _label, int _value, int _index, string _encode){
      label = _label;
      value = _value;
      index = _index;
      encode = _encode;
    }

    int getIndex() { return index; }
    int getValue() { return value; }
    string getLabel() { return label; }
    string getEncode() { return encode; }

    void setValue( int _value ) { value = _value; }
    void setEncode ( string _encode ) { encode = _encode; }

};
