#ifndef ILD_COMPILER_HELPER_H
#define ILD_COMPILER_HELPER_H

#include <iostream>
#include <vector>

using namespace std;
namespace Utils {
    class Helper;

    const string
            VERSION = "ALPHA 0.1";
    const int
            INVALID_USAGE_UNKNOWN_ARGUMENT = 0,
            INVALID_USAGE_NO_SOURCE = 1;
};

class Utils::Helper {
private:
    static Helper *instance;

    Helper() = default;

public:
    static Helper *getInstance();

    string str_to_lower(const string &s);

    vector<string> &convertArgsVector(int argc, char *argv[]);

    void printHelp() const;

    void printInformation() const;

    void printVersion() const;

    void printInvalidInput(const int &error) const;

    void printInvalidUsage(const int &error) const;
};

#endif
