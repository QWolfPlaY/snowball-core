#include "core.h"

#include <vector>


std::vector<core::flag>
core::checkForFlags(int argc, char *argv[], const std::vector<flagToCheck> &flagsToCheck) {
    std::vector<flag> flags = {};

    for (auto &i: flagsToCheck) {
        for (int j = 1; j < argc; j++) {
            if (argv[j] == i.flagString) {
                if (i.withValue) {
                    flags.push_back(flag{
                            i.flagString,   /* flagString */
                            j,              /* index */
                            argv[++j]       /* valueptr */
                    });
                } else {
                    flags.push_back(flag{
                            i.flagString, /* flagString */
                            j             /* index */
                    });
                }
            }
        }
    }
    return flags;
}

void core::toBinFile(char *path, char *data) {
    std::ofstream outFile(path, std::ios::binary);
    if (!outFile) {
        throw std::exception();// REPLACE
    }

    outFile.write(reinterpret_cast<const char *> (data), sizeof(data));
    if (!outFile) {
        throw std::exception();// REPLACE
    }

    outFile.close();
}