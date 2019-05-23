#ifndef ILD_COMPILER_DATA_H
#define ILD_COMPILER_DATA_H

#include <iostream>
#include <vector>

using namespace std;

namespace Data {
    class Data_Node;

    class Stack;

    const int NUMERIC_LIMIT = 127;
    const auto DATA_TYPES = new vector<string>{"intero", "booleano", "carattere"};
};
#endif