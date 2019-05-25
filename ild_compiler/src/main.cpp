#include <iostream>
#include <string>
#include "Utils/Helper.h"
#include "Parser/Parser.h"
#include "Structures/Data/Data.h"

using namespace std;
using namespace Utils;
using namespace Parser;

bool readyToParse(int argc, char *argv[]);

string input_file, output_file;

int main(int argc, char *argv[]) {
    if (readyToParse(argc, argv)) {

      /* PROVA DELLE IST. STDILD */
      fstream output;
      output.open(output_file, fstream::out);
      /* /PROVA DELLE IST. STDILD */

    }
    return 0;
}

bool readyToParse(int argc, char *argv[]) {
    auto args = Helper::getInstance()->convertArgsVector(argc, argv);
    if (args.empty()) {
        cout << "Use -h to get help." << endl;
        cout << "Press any key to continue...";
        cin.get();
    } else {
        if (args[0] == "-h") {
            Helper::getInstance()->printHelp();
        } else if (args[0] == "-v" || args[0] == "-version") {
            Helper::getInstance()->printVersion();
        } else if (args[0] == "-i" || args[0] == "-info") {
            Helper::getInstance()->printInformation();
        } else if (args[0] == "-c" || args[0] == "-dc") {
            if (args.size() >= 2) {
                output_file = args.size() == 3 ? args[2] + ".edmisa" : "out.edmisa";
                input_file = args[1];
                if (Reader::getInstance()->isInputFileSupported(input_file)) {
                    return true;
                }
            } else {
                Helper::getInstance()->printInvalidUsage(INVALID_USAGE_NO_SOURCE);
            }
        } else {
            Helper::getInstance()->printInvalidUsage(INVALID_USAGE_UNKNOWN_ARGUMENT);
        }
    }
    return false;
}
