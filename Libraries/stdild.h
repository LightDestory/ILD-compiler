#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include "../Objects/typenode.h"
using namespace std;

void initReg(fstream& file, string reg, short value);

void initVar(fstream& file, Node *node);

void callForSub(string fun_code, fstream& file, int sp, int pc, int params, Node** buffer);

void exitForSub(fstream& file);
