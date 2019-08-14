#include <iostream>
#include <string>
#include <vector>
#include "Misc/Helper.h"
#include "Parser/Parser.h"

using namespace std;
using namespace Utils;
using namespace Parser;

bool readyToParse(int argc, char *argv[]);

string input_file, output_file;
vector<string> declarations, instructions, errors;

int main(int argc, char *argv[]) {
    if (readyToParse(argc, argv)) {
        
    }
    return 0;
}

bool readyToParse(int argc, char *argv[]) {
    vector<string> args = Helper::getInstance()->convertArgsVector(argc, argv);
    if (args.empty()) {
        Helper::getInstance()->printHelp();
        cin.get();
    } else {
        if (args[0] == "-h") {
            Helper::getInstance()->printHelp(true);
        } else if (args[0] == "-v" || args[0] == "-version") {
            Helper::getInstance()->printVersion();
        } else if (args[0] == "-i" || args[0] == "-info") {
            Helper::getInstance()->printInformation();
        } else if (args[0] == "-c") {
            if (args.size() >= 2) {
                output_file = args.size() == 3 ? args[2] + ".edmisa" : "out.edmisa";
                input_file = args[1];
                if (Reader::getInstance()->isInputFileSupported(input_file)) {
                    return true;
                }
            } else {
                Helper::getInstance()->printInvalidUsage(Utils::INVALID_USAGE_NO_SOURCE);
            }
        } else {
            Helper::getInstance()->printInvalidUsage(Utils::INVALID_USAGE_UNKNOWN_ARGUMENT);
        }
    }
    return false;
}
