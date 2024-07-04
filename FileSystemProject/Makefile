CXX = g++
CXXFLAGS = -std=c++11 -Wall

SRC = src/FileSystem.cpp src/main.cpp
TEST_SRC = tests/test_FileSystem.cpp src/FileSystem.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = filesystem
TEST_EXEC = test_filesystem

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(OBJ) -o $@ $(CXXFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC) $(TEST_EXEC)

test: $(TEST_EXEC)

$(TEST_EXEC): $(TEST_SRC)
	$(CXX) $(TEST_SRC) -o $@ $(CXXFLAGS) -I$(CATCH_INCLUDE_DIR)

.PHONY: clean all test
