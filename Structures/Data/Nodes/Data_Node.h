#ifndef ILD_COMPILER_DATA_NODE_H
#define ILD_COMPILER_DATA_NODE_H

#include "../Data.h"
#include <iostream>

using namespace std;

class Data::Data_Node {
private:
    unsigned int index;
    int value;
    string label, encode;
    bool is_array;

public:
    Data_Node(string _label, int _value, unsigned int _index, string _encode, bool _is_array = false);

    void setEncode(string _encode);

    string getEncode() const;

    void setValue(int _value);

    int getValue() const;

    string getLabel() const;

    unsigned int getIndex() const;

    bool isArray() const;
};

#endif
