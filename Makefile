# Define compiler and flags
CXX = g++
CXXFLAGS = -I./include -Wall -std=c++17
LDFLAGS = -lgtest -lgtest_main

# Define directories
SRCDIR = src
INCDIR = include/linalg
TESTDIR = tests
BUILDDIR = bin
LIBDIR = lib

# Define source and object files
SRC = $(wildcard $(SRCDIR)/*.cpp)
OBJS = $(patsubst $(SRCDIR)/%.cpp, $(LIBDIR)/%.o, $(SRC))
TEST_SRC = $(wildcard $(TESTDIR)/*.cpp)
TEST_OBJS = $(patsubst $(TESTDIR)/%.cpp, $(LIBDIR)/%.o, $(TEST_SRC))
TEST_BIN = $(BUILDDIR)/run_tests

# Default target
all: $(TEST_BIN)

# Build the main objects
$(LIBDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Build the test objects
$(LIBDIR)/%.o: $(TESTDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Link the test executable
$(TEST_BIN): $(OBJS) $(TEST_OBJS)
	$(CXX) $(OBJS) $(TEST_OBJS) $(LDFLAGS) -o $@

# Run tests
test: $(TEST_BIN)
	./$(TEST_BIN)

# Clean up build artifacts
clean:
	rm -f $(LIBDIR)/*.o $(TEST_BIN)

.PHONY: all test clean

