#include "Helper.h"
#include "../Parser/Parser.h"

using namespace Utils;

Helper *Helper::getInstance() {
    if (!instance) {
        instance = new Helper();
    }
    return instance;
}

string Helper::str_to_lower(const string &s) {
    string tmp;
    for (auto c : s)
        tmp += (char) tolower(c);
    return tmp;
}

vector<string> &Helper::convertArgsVector(int argc, char *argv[]) {
    auto tmp = new vector<string>();
    for (int i = 1; i < argc; i++)
        tmp->push_back(str_to_lower(string(argv[i])));
    return *tmp;
}

void Helper::printHelp(const bool verbose) const {
    if(verbose) {
        cout << "\nUsage:\n"
             << "To get info about this project:\n"
             << "\t compiler_executable -i(nfo) \n"
             << "To check the compiler's version:\n"
             << "\t compiler_executable -v(ersion) \n"
             << "To compile a source code use the following command:\n"
             << "\t compiler_executable -c '[source_file]' '[destination_file]'\n";
    }
    else{
        cout << "Use -h to get help.\nPress any key to continue...";
    }
}

void Helper::printInformation() const {
    cout << "ILD Compiler is a project by Alessio Tudisco for 'Architettura degli elaboratori' A.A 2018/2019.\nIt compiles a very basic language in EsEDM assembly code,";
}

void Helper::printVersion() const {
    cout << "ILD Compiler: " << Utils::VERSION;
}

void Helper::printInvalidInput(const int &error) const {
    string err_text;
    switch (error) {
        case Parser::INVALID_INPUT_FILE_UNSUPPORTED:
            err_text = "The selected input file isn't a " + Parser::FILE_EXTENSION + " file!";
            break;
        case Parser::INVALID_INPUT_FILE_NOT_EXISTS:
            err_text = "The selected input file doesn't exist!";
            break;
        case Parser::INVALID_INPUT_FILE_EMPTY:
            err_text = "The selected file is a empty file.";
            break;
    }
    cerr << err_text << "\nPlease refer to the documentation about the compilable language.";
}

void Helper::printInvalidUsage(const int &error) const {
    string err_text;
    switch (error) {
        case Utils::INVALID_USAGE_NO_SOURCE:
            err_text = "No source code selected";
            break;
        case Utils::INVALID_USAGE_UNKNOWN_ARGUMENT:
            err_text = "Detected invalid argument(s)";
            break;
        default:
            err_text = "Unknown Error";
            break;
    }
    cerr << err_text << "\nPlease refer to -h to know how use properly the compiler.";
}

Helper *Helper::instance = NULL;