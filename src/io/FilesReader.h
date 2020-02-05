//
// Created by victor on 5/26/17.
//

#ifndef DBCRUDGEN_CPP_FILESREADER_H
#define DBCRUDGEN_CPP_FILESREADER_H

#include <iostream>
#include <fstream>

class FilesReader {
public:
    FilesReader() {}

    /**
     * Read a file
     *
     * @param filename
     * @return
     */
    std::string readFile(std::string filename) {
        std::string fileData = "";

        std::ifstream handle(filename);

        std::string line;
        while (std::getline(handle, line)) {
          if(fileData == "")
              fileData.append(line);
          else  fileData.append("\n" +line);
        }
        return fileData;
    }

    ~FilesReader() {}
};

#endif //DBCRUDGEN_CPP_FILESREADER_H
