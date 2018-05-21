/**
* @author Victor Mwenda
* @author vmwenda.vm@gmail.com
*
* Created by victor on 6/24/17.
* C/C++ Laptop
*/



#ifndef DBCRUDGEN_CPP_LANGUAGEASSET_H
#define DBCRUDGEN_CPP_LANGUAGEASSET_H

#include <iostream>
#include <vector>
/**
* LanguageAsset
* */
class LanguageFilesProperties {
private:
    std::string fileStorageDir;
    std::string fileType;
    std::vector<std::string> fileExtension;
protected:
    void setFileName(const std::string &fileType) {
        LanguageFilesProperties::fileType = fileType;
    }

    void setFileStorageDir(const std::string &fileStorageDir) {
        LanguageFilesProperties::fileStorageDir = fileStorageDir;
    }

    void setFileExtension(const std::vector<std::string> &fileExtension) {
        LanguageFilesProperties::fileExtension = fileExtension;
    }

public:
    /**
     * Sets the language file properties
     * @param fileStorageDir
     * @param fileType
     * @param fileExtension
     */
    LanguageFilesProperties(std::string fileStorageDir, std::string fileType,
                            std::vector<std::string> fileExtension) :
            fileType(fileType), fileStorageDir(fileStorageDir), fileExtension(fileExtension) {}

    const std::string &getFileStorageDir() const {
        return fileStorageDir;
    }

    const std::string &getFileType() const {
        return fileType;
    }

    const std::vector<std::string> &getFileExtension() const {
        return fileExtension;
    }
};


#endif //DBCRUDGEN_CPP_LANGUAGEASSET_H
