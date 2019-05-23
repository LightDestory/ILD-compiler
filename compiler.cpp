#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include "Objects/typenode.h"
//#include "Objects/parser.h"
#include "Libraries/stdild.h"

using namespace std;

#define STACK_LIMIT 127

int main(int argc, char** argv) {
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

  Stack nodes(STACK_LIMIT);
  nodes.init(0,"pippo", 128, 0, "intero");
  nodes.init(1,"nino", 6, 1, "intero");
  nodes.init(2,"alfredo", 0, 2, "intero");

  nodes.init(3,"salvatore", -100, 3, "intero");
  nodes.init(4,"luigi", 0, 4, "intero");



  // if(nodes[0])
  //   nodes[0] = new Node("nino", 128, 0, "intero");

  /* PRIMA PASSATA */
  int used_stack = 4;

  /* HEADER DEL FILE DI OUTPUT */
  outfile << "ADD-SP-SP-#"<<used_stack<<"#!" << endl;

  if(nodes[0])
    initVar(outfile, nodes[0]);
    initVar(outfile, nodes[1]);
    initVar(outfile, nodes[2]);
    initVar(outfile, nodes[3]);
    initVar(outfile, nodes[4]);

    sub(outfile, nodes[2], nodes[0], nodes[1]);
    sum(outfile, nodes[4], nodes[2], nodes[3]);

    // initReg(outfile, "R1", stack[0]->getValue());

  infile.close();
  outfile.close();

}
