#include <string>
#include <vector>
#include "Parser.h"
#include "../Utils/Helper.h"

using namespace Parser;

Reader *Reader::getInstance() {
    if (!instance) {
        instance = new Reader();
    }
    return instance;
}

bool Reader::isInputFileSupported(const string &input_file) {
    if (input_file.length() >= 5 &&
        Utils::Helper::getInstance()->str_to_lower(input_file.substr(input_file.length() - 4)) == FILE_EXTENSION) {
        input.open(input_file);
        if (input.is_open()) {
            return true;
        } else {
            Utils::Helper::getInstance()->printInvalidInput(INVALID_INPUT_FILE_NOT_EXISTS);
        }
    } else {
        Utils::Helper::getInstance()->printInvalidInput(INVALID_INPUT_FILE_UNSUPPORTED);
    }
    return false;
}

void Reader::parse(vector<string> declarations, vector<string> instructions, vector<string> errors) {
    return;
}

bool Reader::isInputEmpty() {
    return input.peek() == fstream::traits_type::eof();
}

Reader *Reader::instance = NULL;
