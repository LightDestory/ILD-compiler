#ifndef ILD_COMPILER_PARSER_H
#define ILD_COMPILER_PARSER_H

#include <fstream>
#include <vector>

using namespace std;

namespace Parser {
    class Reader;

    const string FILE_EXTENSION = ".ild";
    const int
            INVALID_INPUT_FILE_UNSUPPORTED = 0,
            INVALID_INPUT_FILE_NOT_EXISTS = 1;
}
class Parser::Reader {
private:
    static Reader *instance;

    Reader() = default;

    fstream input;
public:
    static Reader *getInstance();

    bool isInputFileSupported(const string &input_file);
};

#endif
