#include "FileSystem.hpp"
#include <iostream>

int main() {
    FileSystem fs;

    // Creating a file
    if (fs.createFile("/home/user/test.txt")) {
        std::cout << "File created successfully.\n";
    } else {
        std::cout << "Failed to create file.\n";
    }

    // Writing to a file
    if (fs.writeFile("/home/user/test.txt", "Hello, World!")) {
        std::cout << "File written successfully.\n";
    } else {
        std::cout << "Failed to write file.\n";
    }

    // Reading a file
    std::string content = fs.readFile("/home/user/test.txt");
    if (!content.empty()) {
        std::cout << "File content: " << content << "\n";
    } else {
        std::cout << "Failed to read file.\n";
    }

    // Deleting a file
    if (fs.deleteFile("/home/user/test.txt")) {
        std::cout << "File deleted successfully.\n";
    } else {
        std::cout << "Failed to delete file.\n";
    }

    return 0;
}
