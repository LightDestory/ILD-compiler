#include <iostream>
#include <fstream>
#include "parser.h"
#include "typenode.h"
using namespace std;

Parser::Parser (Node** _stack, int _stack_size) {
  Parser::stack = _stack;
  Parser::stack_size = _stack_size;
}

int Parser::firstPass(fstream& file) {
  return 0; 
}
