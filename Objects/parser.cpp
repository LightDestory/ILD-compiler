#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "parser.h"
#include "typenode.h"
using namespace std;

Parser::Parser (Node** _stack, int _stack_size) {
  Parser::stack = _stack;
  Parser::stack_size = _stack_size;
  Parser::stack_pop = 0;
}

//prova dichiarazione variabile
int Parser::firstPass(fstream& file) {
  vector<string> sintax;
  string line;
  while(getline(file, line)) {
    sintax.clear();
    sintax.push_back(line);
    if(sintax[0] == "intero" || sintax[0] == "booleano" || sintax[0] == "carattere") {
      //dichiarazione variabile
      string name ="";// sintax[1];
      stringstream ss(sintax[3]);
      int value;
      ss >> value;
      string code;
      if(sintax[0] == "intero" || sintax[0] == "booleano" )
        code = "num";
      else code = "ascii";
      Parser::stack[stack_pop] = new Node(name, value, stack_pop, code);
      cout << name << " " << value << " " << stack_pop << " " << code << endl;
      stack_pop++;
    }
  }
  return stack_pop;
}
