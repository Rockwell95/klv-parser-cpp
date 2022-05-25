#include <iostream>
#include <Config.h>
#include "klvparser/StreamParser.h"

using std::byte;

int main(/* int argc, char* argv[] */) {
    std::cout << "KlvParser version" << StanagKlvParser_VERSION_MAJOR << "." << StanagKlvParser_VERSION_MAJOR
              << std::endl;

    std::ifstream stream;

    for (const auto &[key, value]: StreamParser(stream)) {
        try {
            /* code */
        }
        catch (const std::exception &e) {
            std::cerr << "Oops! " << e.what() << " occurred." << '\n';
        }
    }
}