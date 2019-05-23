#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include "../Objects/typenode.h"
using namespace std;

/* file di prova da revisionare. */

/* INIZIALIZZAZIONE REGISTRO (NON UTILIZZARE R3) */
void initReg(fstream& file, string reg, short value) {
  if(value >= -128 && value <= 127) {
    file << "MOV-"<<reg<<"-#"<<value<<"#!" << endl;
    return;
  }
  if(value > 127) {
    file << "MOV-"<<reg<<"-#127#!"<<endl;
    file << "MOV-R3-#127#!"<<endl;
    value-=127;
    while(value > 127) {
      file << "ADD-"<<reg<<"-"<<reg<<"-R3!"<<endl;
      value-=127;
    }
    file << "MOV-R3-#"<<value<<"#!"<<endl;
    file << "ADD-"<<reg<<"-"<<reg<<"-R3!"<<endl;
  }
  if(value < -128) {
    file << "MOV-"<<reg<<"-#-128#!"<<endl;
    file << "MOV-R3-#-128#!"<<endl;
    value+=128;
    while(value < -128) {
      file << "ADD-"<<reg<<"-"<<reg<<"-R3!"<<endl;
      value+=128;
    }
    file << "MOV-R3-#"<<value<<"#!"<<endl;
    file << "ADD-"<<reg<<"-"<<reg<<"-R3!"<<endl;
  }
}

/* INIZIALIZZAZIONE VARIABILE IN MEMORIA */
void initVar(fstream& file, Node *node) {
  initReg(file, "R1", node->getValue());
  file << "SBT-R0-SP-#"<<node->getIndex()<<"#!"<<endl;
  file << "STR-R1-R0!"<<endl;
}

/* CHIAMATA A SOTTOPROGRAMMA */
/*NOTE:  params = grandezza di buffer => parametri passati */
void callForSub(string fun_code, fstream& file, int sp, int pc, int params, Node** buffer) {
  file << "MOV-R0-SP!" << endl;
  for(int i = 0; i < params; i++) {
    file << "ADD-SP-SP-#1#!" << endl;
    file << "SBT-R2-R0-#"<<buffer[i]->getIndex()<<"#!" << endl;
    file << "STR-R2-SP!" << endl;
  }
  file << "ADD-SP-SP-#1#!" << endl;
  file << "STR-R0-SP!" << endl;
  file << "ADD-SP-SP-#1#!" << endl;
  file << "ADD-R0-PC-#2#!" << endl;
  file << "STR-R0-SP!" << endl;
  file << "BRA-("<<fun_code<<")!"<<endl;
}

/* RITORNO DA SOTTOPROGRAMMA */
void exitForSub(fstream& file) {
  file << "MOV-R0-SP!" << endl;
  file << "SBT-SP-SP-#1#!" << endl;
  file << "LDR-SP-SP!" << endl;
  file << "LDR-PC-R0!" << endl;
}

void sum(fstream& file, Node *dest, Node *op1, Node *op2) {
  file << "SBT-R1-SP-#" << op1->getIndex() << "#!" << endl;
  file << "SBT-R2-SP-#" << op2->getIndex() << "#!" << endl;
  file << "LDR-R1-R1!" << endl;
  file << "LDR-R2-R2!" << endl;
  file << "ADD-R1-R1-R2!" << endl;
  file << "SBT-R2-SP-#"<< dest->getIndex() << "#!" << endl;
  file << "STR-R1-R2!" << endl;
}

void sub(fstream& file, Node *dest, Node *op1, Node *op2) {
  file << "SBT-R1-SP-#" << op1->getIndex() << "#!" << endl;
  file << "SBT-R2-SP-#" << op2->getIndex() << "#!" << endl;
  file << "LDR-R1-R1!" << endl;
  file << "LDR-R2-R2!" << endl;
  file << "SBT-R1-R1-R2!" << endl;
  file << "SBT-R2-SP-#"<< dest->getIndex() << "#!" << endl;
  file << "STR-R1-R2!" << endl;
}

void mul(fstream& file, Node *dest, Node *op1, Node *op2) {
  
}
