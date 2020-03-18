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
     * @param path
     * @return
     */
    static bool createDirs(std::string path) {

        //Add a trailing file separator to create all dirs in path
        if (path[path.size() - 1] != '/') {
            path += "/";
        }

        bool response = false;

        std::string parentDir;
        int currentPosition = 0;
        std::string separator = "/";

        struct stat *info = nullptr;

        while ((currentPosition = path.find_first_of(separator, currentPosition)) != std::string::npos) {

            parentDir = path.substr(0, currentPosition);
            currentPosition++;

            std::cout << "Parent dir : " << parentDir << std::endl;

            //Skip root dir
            if (parentDir.empty()) continue;

            int statRC = stat(parentDir.c_str(), info);

            if (statRC != 0) {

                int status = mkdir(parentDir.c_str(), 0777);

                switch (status) {
                    case 0:
                        response = true;
                        std::cout << "creating directory at " << parentDir << std::endl;
                        break;
                    case -1:
                        response = true;
                        break;
                    case EEXIST:
                        response = true;
                        break;
                    default:
                        response = false;
                        std::cout << "Failed with errno : [" << status << "] (" << parentDir << ")" << std::endl;
                }

            } else {
                if (errno == ENOENT) {
                    //something along the path does not exists
                    std::cout << "something along the path does not exists" << std::endl;
                    response = false;
                } else if (errno == ENOTDIR) {
                    //something along the path is not directory
                    std::cout << "something along the path is not directory" << std::endl;
                    response = false;
                } else {
                    std::cout << "unhandled error " << errno << std::endl;
                    response = false;
                }
            }

        }

        return response;
    }


    ~FilesWriter() = default;


};

#endif //DBCRUDGEN_CPP_FILESWRITER_H
