#include "stdild.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include "../Structures/Data/Data.h"
#include "../Structures/Data/Nodes/Data_Node.h"

using namespace std;
using namespace Data;
/* file di prova da revisionare. */

/* INIZIALIZZAZIONE REGISTRO (NON UTILIZZARE R3) */
void initReg(fstream &file, string reg, short value) {
    if (value >= -128 && value <= 127) {
        file << "MOV-" << reg << "-#" << value << "#!" << endl;
        return;
    }
    if (value > 127) {
        file << "MOV-" << reg << "-#127#!" << endl;
        file << "MOV-R3-#127#!" << endl;
        value -= 127;
        while (value > 127) {
            file << "ADD-" << reg << "-" << reg << "-R3!" << endl;
            value -= 127;
        }
        file << "MOV-R3-#" << value << "#!" << endl;
        file << "ADD-" << reg << "-" << reg << "-R3!" << endl;
    }
    if (value < -128) {
        file << "MOV-" << reg << "-#-128#!" << endl;
        file << "MOV-R3-#-128#!" << endl;
        value += 128;
        while (value < -128) {
            file << "ADD-" << reg << "-" << reg << "-R3!" << endl;
            value += 128;
        }
        file << "MOV-R3-#" << value << "#!" << endl;
        file << "ADD-" << reg << "-" << reg << "-R3!" << endl;
    }
}

/* INIZIALIZZAZIONE VARIABILE IN MEMORIA */
void initVar(fstream &file, Data_Node *node) {
    initReg(file, "R1", node->getValue());
    file << "SBT-R0-SP-#" << node->getIndex() << "#!" << endl;
    file << "STR-R1-R0!" << endl;
}

/* CHIAMATA A SOTTOPROGRAMMA */
/* NOTE:  params = grandezza di buffer => parametri passati */
/* USO: Passiamo un buffer di variabili da passare al sottoprogramma */
void callForSub(string fun_code, fstream &file, int sp, int pc, int params, Data_Node **buffer) {
    file << "MOV-R0-SP!" << endl;
    for (int i = 0; i < params; i++) {
        file << "ADD-SP-SP-#1#!" << endl;
        file << "SBT-R2-R0-#" << buffer[i]->getIndex() << "#!" << endl;
        file << "STR-R2-SP!" << endl;
    }
    file << "ADD-SP-SP-#1#!" << endl;
    file << "STR-R0-SP!" << endl;
    file << "ADD-SP-SP-#1#!" << endl;
    file << "ADD-R0-PC-#2#!" << endl;
    file << "STR-R0-SP!" << endl;
    file << "BRA-(" << fun_code << ")!" << endl;
}

/* RITORNO DA SOTTOPROGRAMMA */
void exitForSub(fstream &file) {
    file << "MOV-R0-SP!" << endl;
    file << "SBT-SP-SP-#1#!" << endl;
    file << "LDR-SP-SP!" << endl;
    file << "LDR-PC-R0!" << endl;
}

void sum(fstream &file, Data_Node *dest, Data_Node *op1, Data_Node *op2) {
    file << "SBT-R1-SP-#" << op1->getIndex() << "#!" << endl;
    file << "SBT-R2-SP-#" << op2->getIndex() << "#!" << endl;
    file << "LDR-R1-R1!" << endl;
    file << "LDR-R2-R2!" << endl;
    file << "ADD-R1-R1-R2!" << endl;
    file << "SBT-R2-SP-#" << dest->getIndex() << "#!" << endl;
    file << "STR-R1-R2!" << endl;
}

void sub(fstream &file, Data_Node *dest, Data_Node *op1, Data_Node *op2) {
    file << "SBT-R1-SP-#" << op1->getIndex() << "#!" << endl;
    file << "SBT-R2-SP-#" << op2->getIndex() << "#!" << endl;
    file << "LDR-R1-R1!" << endl;
    file << "LDR-R2-R2!" << endl;
    file << "SBT-R1-R1-R2!" << endl;
    file << "SBT-R2-SP-#" << dest->getIndex() << "#!" << endl;
    file << "STR-R1-R2!" << endl;
}

void isGreater(fstream &file, Data_Node *dest, Data_Node *op1, Data_Node *op2, bool isEqual) {
    file << "SBT-R1-SP-#" << op1->getIndex() << "#!" << endl;
    file << "SBT-R2-SP-#" << op2->getIndex() << "#!" << endl;
    file << "MOV-R3-#0#!" << endl; // Supporto
    file << "LDR-R1-R1!" << endl;
    file << "LDR-R2-R2!" << endl;
    file << "SBT-R1-R1-R2!" << endl;
    file << "SBT-R2-SP-#" << dest->getIndex() << "#!" << endl;
    file << "CMP-R1-#0#!" << endl;
    if(!isEqual) file << "BGT-(IS_GREATER)!" << endl; // Dovrebbe controllare se R1 > 0
    else file << "BGE-(IS_GREATER)!" << endl; // Dovrebbe controllare se R1 >= 0
    file << "MOV-R3-#0#!" << endl;
    file << "BRA(END_IS_GREATER)!" << endl;
    /*
     * MI MANCA LA DOCUMENTAZIONE ESEDM.
     * Non conoscendo la logica dei salti, ho dovuto creare una variabile di supporto
     * su cui caricare il risultato e fare in una salvataggio generale imponendo
     * un salto non condizionato al END_IS_GREATER
     */
    file << "<IS_GREATER>" << endl;
    file << "MOV-R3-#1#!" << endl;
    file << "<END_IS_GREATER>" << endl;
    file << "STR-R2-R3!" << endl;

}

void isGreaterEqual(fstream &file, Data_Node *dest, Data_Node *op1, Data_Node *op2){
    isGreater(file, dest, op1, op2, true);
}

void isLess(fstream &file, Data_Node *dest, Data_Node *op1, Data_Node *op2, bool isEqual) {
    file << "SBT-R1-SP-#" << op1->getIndex() << "#!" << endl;
    file << "SBT-R2-SP-#" << op2->getIndex() << "#!" << endl;
    file << "MOV-R3-#0#!" << endl; // Supporto
    file << "LDR-R1-R1!" << endl;
    file << "LDR-R2-R2!" << endl;
    file << "SBT-R1-R1-R2!" << endl;
    file << "SBT-R2-SP-#" << dest->getIndex() << "#!" << endl;
    file << "CMP-R1-#0#!" << endl;
    if(!isEqual) file << "BLT-(IS_LESS)!" << endl; // Dovrebbe controllare se R1 < 0
    else file << "BGE-(IS_LESS)!" << endl; // Dovrebbe controllare se R1 <= 0
    file << "MOV-R3-#0#!" << endl;
    file << "BRA(END_IS_LESS)!" << endl;
    /*
     * MI MANCA LA DOCUMENTAZIONE ESEDM.
     * Non conoscendo la logica dei salti, ho dovuto creare una variabile di supporto
     * su cui caricare il risultato e fare in una salvataggio generale imponendo
     * un salto non condizionato al END_IS_LESS
     */
    file << "<IS_LESS>" << endl;
    file << "MOV-R3-#1#!" << endl;
    file << "<END_IS_LESS>" << endl;
    file << "STR-R2-R3!" << endl;
}

void isLessEqual(fstream &file, Data_Node *dest, Data_Node *op1, Data_Node *op2){
    isLess(file, dest, op1, op2, true);
}

void pow(fstream &file, Data_Node *dest, Data_Node *op1, Data_Node *op2){
    file << "SBT-R1-SP-#" << op1->getIndex() << "#!" << endl; // Base
    file << "SBT-R2-SP-#" << op2->getIndex() << "#!" << endl; // Potenza
    file << "SBT-R3-SP-#" << dest->getIndex() << "#!" << endl;
    file << "LDR-R1-R1!" << endl; // Base
    file << "LDR-R2-R2!" << endl; // Potenza
    file << "MOV-R4-#0#!" << endl; // Supporto del risultato
    file << "CMP-R1-#0#!" << endl;
    file << "BEQ-(NULL_BASE)!" << endl; // Controlla se Base == 0
    file << "CMP-R2-#1#!" << endl;
    file << "BEQ-(ONE_POW)!" << endl; // Controlla se Potenza == 1
    file << "CMP-R2-#0#!" << endl;
    file << "BEQ-(NULL_POW)!" << endl; // Controlla se Potenza == 0
    file << "<START_POWING>" << endl;
    file << "SBT-R2-#1#!" << endl;
    file << "MOV-R5-#R1#!" << endl; // Supporto2 di potenza
    file << "<SUM_POWING>" << endl;
    file << "SBT-R5-#1#!" << endl;

    // DA FINIRE
    file << "ADD-R4-R4-R6" << endl;
    file << "CMP-R5-#1#!" << endl;
    file << "BGT-(START_POWING)" << endl;
    file << "CMP-R2-#1#!" << endl;
    file << "BGT-(START_POWING)" << endl; // Controlla se Potenza > 0
    file << "BRA(END_POWING)!" << endl;
    /*
     * MI MANCA LA DOCUMENTAZIONE ESEDM.
     * Cosa faccio a uscire dall'esecuzione ed evitare che vada ad eseguire
     * il resto?
     */
    file << "<NULL_BASE>" << endl;
    file << "MOV-R4-#0#!" << endl; // 0 elevato a qualsiasi numero = 0;
    file << "BRA(END_POWING)!" << endl;
    file << "<ONE_POW>" << endl;
    file << "MOV-R4-R1!" << endl; // Qualsiasi numero elevato a 1 = se stesso
    file << "BRA(END_POWING)!" << endl;
    file << "<NULL_POW>" << endl;
    file << "MOV-R4-#1#!" << endl; // Qualsiasi numero elevato a 0 = 1
    file << "<END_POWING>" << endl;
    file << "STR-R3-R4!" << endl;
}

/* R1 => adr risultato, R2 => primo operando, R3 => secondo operando  */
/* il posto 0 e 1 è riservato per PC e SP*/
void mul(fstream &file) {
  file << "<MULTIPLICATION>" << endl;
  file << "SBT-R1-SP-#2#!" << endl; //destinazione
  file << "SBT-R2-SP-#3#!" << endl; //primo valore
  file << "SBT-R0-SP-#4#!" << endl; //secondo valore
  // start algorithm
  file << "LDR-R1-R1!" <<  endl;
  file << "LDR-R2-R2!" <<  endl;
  file << "MOV-R3-#0#!" << endl;
  file << "CMP-R1-#0#!" << endl;
  file << "BRL-(MULTIPLICATION_NEGATIVE_WHILE)!" << endl;
  file << "<MULTIPLICATION_POSITIVE_WHILE>" << endl;
  file << "ADD-R3-R3-R2!" << endl;
  file << "SBT-R1-R1-#1#!" << endl;
  file << "CMP-R1-#0#!" << endl;
  file << "BRG-(MULTIPLICATION_POSITIVE_WHILE)!" << endl;
  file << "BRA-(MULTIPLICATION_SAVE_RESULT)!" << endl;
  file << "<MULTIPLICATION_NEGATIVE_WHILE>" << endl;
  file << "SBT-R3-R3-R2!" << endl;
  file << "ADD-R1-R1-#1#!" << endl;
  file << "CMP-R1-#0#!" << endl;
  file << "BRL-(MULTIPLICATION_NEGATIVE_WHILE)!" << endl;
  file << "<MULTIPLICATION_SAVE_RESULT>" << endl;
  // end algorithm
  file << "STR-R3-R0!" << endl; //store nella destinazione
}
