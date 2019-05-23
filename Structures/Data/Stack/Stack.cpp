#include "Stack.h"
#include "../Nodes/Data_Node.h"
#include<iostream>

using namespace std;
using namespace Data;

Stack::Stack(int _stack_max) {
    stack_max = _stack_max;
    variables = new Data_Node *[stack_max];
    count = 0;
}

void Stack::insertTable(string label, int value, string encode, bool is_array) {
    if (count >= Stack::stack_max) return;
    variables[count++] = new Data_Node(label, value, count - 1, encode, is_array);
}

Stack *Stack::getInstance(int _stack_max) {
    if (!instance)
        instance = new Stack(_stack_max);
    return instance;
}

Data_Node *Stack::operator[](unsigned int i) {
    if (i < stack_max) {
        return variables[i];
    }
    return NULL;
}

Data_Node *Stack::findByIndex(unsigned int i) {
    return (*Stack::getInstance())[i];
}

Data_Node *Stack::findByLabel(string label) {
    for (int i = 0; i < count; i++) {
        if (variables[i]->getLabel() == label)
            return variables[i];
    }
    return NULL;
}

Stack *Stack::instance = NULL;