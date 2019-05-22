#ifndef __PARSER_H__
#define __PARSER_H__

#include <iostream>
#include <fstream>
#include "typenode.h"
using namespace std;

class Parser {

  private:
    Node** stack;
    int stack_size, stack_pop;

  public:

    Parser(Node** _stack, int _stack_size);

    int firstPass(fstream& file);

};

#endif
