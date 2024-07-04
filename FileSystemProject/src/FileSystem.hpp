#ifndef FILESYSTEM_HPP
#define FILESYSTEM_HPP

#include <string>
#include <unordered_map>

class File {
public:
    std::string name;
    std::string content;

    File(const std::string &name) : name(name), content("") {}
};

class Directory {
public:
    std::unordered_map<std::string, File> files;
    std::unordered_map<std::string, Directory> directories;
};

class FileSystem {
private:
    Directory root;

    Directory* navigateToDirectory(const std::string &path);
public:
    bool createFile(const std::string &path);
    bool writeFile(const std::string &path, const std::string &content);
    std::string readFile(const std::string &path);
    bool deleteFile(const std::string &path);
};

#endif // FILESYSTEM_HPP
