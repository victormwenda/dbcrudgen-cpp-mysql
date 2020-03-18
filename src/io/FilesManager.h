//
// Created by victor on 5/26/17.
//

#ifndef DBCRUDGEN_CPP_FILESMANAGER_H
#define DBCRUDGEN_CPP_FILESMANAGER_H

#include "FilesReader.h"
#include "FilesWriter.h"

class FilesManager {

public:
    FilesReader filesReader;
    FilesWriter filesWriter;

    FilesManager() = default;

    FilesReader *getReader() {
        return (&filesReader);
    }

    FilesWriter *getWriter() {
        return (&filesWriter);
    }

    /**
     * Read file
     * @param filename
     * @return
     */
    std::string readFile(std::string filename) {
        return getReader()->readFile(filename);
    }

    ~FilesManager() = default;
};

#endif //DBCRUDGEN_CPP_FILESMANAGER_H
