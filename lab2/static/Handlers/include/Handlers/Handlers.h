#ifndef HANDLERS_H
#define HANDLERS_H
#include <cstring>
#include <limits>
#include <iostream>

#ifndef PROMPT
#define PROMPT "> "
#endif

namespace Handler {
    int getInt(
        std::istream &stream = std::cin,
        int min = std::numeric_limits<int>::lowest(),
        int max = std::numeric_limits<int>::max()
    );

    // double getDouble(double min, double max);
    // double getDouble(double min = std::numeric_limits<int>::lowest(), double max);
    // double getDouble(double min, double max = std::numeric_limits<int>::max());
    double getDouble(
        std::istream &stream = std::cin,
        double min = std::numeric_limits<double>::lowest(),
        double max = std::numeric_limits<double>::max()
    );
    std::string getString(std::istream &stream = std::cin);
    int countIntLength(int link);
}

#endif