#include "FileSystem.hpp"
#include <sstream>
#include <iostream>

Directory* FileSystem::navigateToDirectory(const std::string &path) {
    std::istringstream iss(path);
    std::string token;
    Directory *current = &root;
    while (std::getline(iss, token, '/')) {
        if (current->directories.find(token) == current->directories.end()) {
            current->directories[token] = Directory();
        }
        current = &current->directories[token];
    }
    return current;
}

bool FileSystem::createFile(const std::string &path) {
    std::string directoryPath = path.substr(0, path.find_last_of('/'));
    std::string fileName = path.substr(path.find_last_of('/') + 1);
    Directory *dir = navigateToDirectory(directoryPath);
    if (dir->files.find(fileName) != dir->files.end()) {
        return false; // File already exists
    }
    dir->files[fileName] = File(fileName);
    return true;
}

bool FileSystem::writeFile(const std::string &path, const std::string &content) {
    std::string directoryPath = path.substr(0, path.find_last_of('/'));
    std::string fileName = path.substr(path.find_last_of('/') + 1);
    Directory *dir = navigateToDirectory(directoryPath);
    if (dir->files.find(fileName) == dir->files.end()) {
        return false; // File does not exist
    }
    dir->files[fileName].content = content;
    return true;
}

std::string FileSystem::readFile(const std::string &path) {
    std::string directoryPath = path.substr(0, path.find_last_of('/'));
    std::string fileName = path.substr(path.find_last_of('/') + 1);
    Directory *dir = navigateToDirectory(directoryPath);
    if (dir->files.find(fileName) == dir->files.end()) {
        return ""; // File does not exist
    }
    return dir->files[fileName].content;
}

bool FileSystem::deleteFile(const std::string &path) {
    std::string directoryPath = path.substr(0, path.find_last_of('/'));
    std::string fileName = path.substr(path.find_last_of('/') + 1);
    Directory *dir = navigateToDirectory(directoryPath);
    if (dir->files.find(fileName) == dir->files.end()) {
        return false; // File does not exist
    }
    dir->files.erase(fileName);
    return true;
}
