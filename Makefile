CPP = g++
CPP_FLAGS = -Wall -g
SOURCE_DIR = src
SRC = $(SOURCE_DIR)/LM35IC.cpp
INCLUDE = $(SOURCE_DIR)/LM35IC.h
OBJ_DIR = obj
OBJ = $(OBJ_DIR)/LM35IC.o
TEST_DIR = tests
TEST_BIN = $(TEST_DIR)/bin
TEST_SOURCES = $(wildcard $(TEST_DIR)/*.cpp)
TESTS = $(TEST_BIN)/tests.out

.PHONY:
all: runTests

$(OBJ): $(SRC) $(INCLUDE)
	$(CPP) $(CPP_FLAGS) -c $< -o $@

$(TESTS): $(TEST_SOURCES) $(OBJ)
	$(CPP) $(CPP_FLAGS) $^ -I src/ -lCppUTest -o $@

.PHONY:
lib: $(OBJ)
	@echo "Library built."

.PHONY:
runTests: $(TESTS)
	tests/bin/tests.out
	@echo "Tests run."

.PHONY:
clean:
	rm -r $(OBJ_DIR)/* $(TEST_BIN)/*
	@echo "All files were successfully deleted."