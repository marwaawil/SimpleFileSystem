#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "filesystem.hpp"

TEST_CASE("File operations", "[filesystem]") {
    FileSystem fs;

    SECTION("Create and check file existence") {
        REQUIRE(fs.createFile("/home/user/test.txt"));
        REQUIRE_FALSE(fs.createFile("/home/user/test.txt")); // File already exists
        REQUIRE(fs.createFile("/home/user/test2.txt"));
        REQUIRE(fs.createFile("/home/user/testdir/test3.txt"));
        REQUIRE(fs.createFile("/home/user/testdir/test4.txt"));

        REQUIRE(fs.deleteFile("/home/user/test2.txt"));
        REQUIRE_FALSE(fs.deleteFile("/home/user/test2.txt"));
    }

    SECTION("Write and read file content") {
        REQUIRE(fs.createFile("/home/user/test.txt"));
        REQUIRE(fs.writeFile("/home/user/test.txt", "Hello, World!"));
        REQUIRE(fs.readFile("/home/user/test.txt") == "Hello, World!");

        REQUIRE_FALSE(fs.writeFile("/home/user/nonexistent.txt", "Hello!")); // File does not exist
        REQUIRE(fs.readFile("/home/user/nonexistent.txt") == ""); // File does not exist

        REQUIRE(fs.deleteFile("/home/user/test.txt"));
    }
}
