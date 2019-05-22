#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include "Objects/typenode.h"
#include "Objects/parser.h"
#include "Libraries/stdild.h"

using namespace std;

#define STACK_LIMIT 127

int main(int argc, char** argv) {

  // Scanner scanner;
  string buffer;

  string input = argv[1];
  string output = "a.edmisa";
  if(argc > 2) {
    output = argv[2];
    output += ".edmisa";
  }

  fstream infile, outfile;
  infile.open(input, fstream::in);
  outfile.open(output, fstream::out);

  if(!infile) {
    cerr << "La ricerca del file ha fallito." << endl;
    return 0;
  }

  /* FILE APERTO */

  Node* stack[STACK_LIMIT];
  // Parser parser(stack, STACK_LIMIT);
  // int stack_size = ;

  stack[0] = new Node("nino", 5000, 0, "intero");

  /* PRIMA PASSATA */
  int used_stack = 0;

  /* HEADER DEL FILE DI OUTPUT */
  outfile << "ADD-SP-SP-#"<<used_stack<<"#!" << endl;

  initVar(outfile, stack[0]);
  // initReg(outfile, "R1", stack[0]->getValue());

  infile.close();
  outfile.close();

}
