//
// Created by victor on 5/26/17.
//

#ifndef DBCRUDGEN_CPP_FILESWRITER_H
#define DBCRUDGEN_CPP_FILESWRITER_H

#include <fstream>
#include <string>
#include <sys/stat.h>

class FilesWriter {
public:
    FilesWriter() = default;

    /**
     * Write file
     * @param filename
     * @param content
     * @return
     */
    static bool writeFile(std::string &filename, std::string &content) {

        std::ofstream handle(filename.c_str());

        if (!handle.is_open()) {
            return false;
        }

        handle << content;

        handle.close();

        return true;

    }

    /**
     * Create directory
     * @param dir
     * @return
     */
    static bool createDir(std::string &dir) {

        int status = mkdir(dir.c_str(), 0777);

        return status == EEXIST || status == 0;

    }

    /**
     * Create multiple directories
     * @param dir
     * @return
     */
    static bool createDirs(std::string &dir) {

        int status = mkdir(dir.c_str(), 0777);

        return status == EEXIST;

    }

    ~FilesWriter() = default;


};

#endif //DBCRUDGEN_CPP_FILESWRITER_H
