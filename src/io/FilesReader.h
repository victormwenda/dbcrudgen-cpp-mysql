//
// Created by victor on 5/26/17.
//

#ifndef DBCRUDGEN_CPP_FILESREADER_H
#define DBCRUDGEN_CPP_FILESREADER_H

#include <iostream>
#include <fstream>

class FilesReader {
public:
    FilesReader() = default;

    /**
     * Read a file
     *
     * @param filename
     * @return
     */
    static std::string readFile(std::string &filename) {
        std::string fileData;

        std::ifstream handle(filename);

        std::string line;

        while (std::getline(handle, line)) {

            if (fileData.empty()) {
                fileData.append(line);
            } else {
                fileData.append("\n" + line);
            }
        }

        return fileData;
    }

    ~FilesReader() = default;
};

#endif //DBCRUDGEN_CPP_FILESREADER_H
