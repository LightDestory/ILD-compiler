#ifndef ILD_COMPILER_STACK_H
#define ILD_COMPILER_STACK_H

#include <iostream>
#include "../Data.h"
using namespace std;
using namespace Data;

class Data::Stack {
private:
    static Stack* instance;
    Data_Node** variables;
    int count, stack_max;
    Stack(int _stack_max);
public:
    static Stack* getInstance(int _stack_max = 128);
    void insertTable(string label, int value, string encode, bool is_array);
    Data_Node* operator[](unsigned int i);
    Data_Node* findByIndex(unsigned int i);
    Data_Node* findByLabel(string label);
};


#endif
