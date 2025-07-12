# Makefile for Week 5 programming assignment
CXX = g++
CXXFLAGS = -std=c++11 -Wall -O2
TARGET = tuan5
TEST_TARGET = test
SOURCE = tuan5_algorithms.cpp
TEST_SOURCE = test_cases.cpp

all: $(TARGET) $(TEST_TARGET)

$(TARGET): $(SOURCE)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCE)

$(TEST_TARGET): $(TEST_SOURCE)
	$(CXX) $(CXXFLAGS) -o $(TEST_TARGET) $(TEST_SOURCE)

run: $(TARGET)
	./$(TARGET)

test: $(TEST_TARGET)
	./$(TEST_TARGET)

clean:
	rm -f $(TARGET) $(TEST_TARGET)

.PHONY: all run test clean