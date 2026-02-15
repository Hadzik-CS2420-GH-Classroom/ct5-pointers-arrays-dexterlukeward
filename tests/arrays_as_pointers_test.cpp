#include <gtest/gtest.h>
#include <sstream>
#include <iostream>
#include "arrays_as_pointers.h"

// Helper: capture stdout from arraysAsPointers()
static std::string captureOutput() {
    std::stringstream buffer;
    std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());
    arraysAsPointers();
    std::cout.rdbuf(oldCout);
    return buffer.str();
}

// ==================== 1. Array Decay to Pointer ====================

TEST(ArraysAsPointersTest, ArrayDecayCallsPrintArray) {
    std::string output = captureOutput();
    EXPECT_TRUE(output.find("Inside printArray (received as pointer):") != std::string::npos)
        << "Should call printArray with the grades array";
    EXPECT_TRUE(output.find("*(arr + 0) = 95") != std::string::npos)
        << "printArray should print first element via pointer arithmetic";
    EXPECT_TRUE(output.find("*(arr + 4) = 88") != std::string::npos)
        << "printArray should print last element via pointer arithmetic";
}

// ==================== 2. Pointer Arithmetic on Array Name ====================

TEST(ArraysAsPointersTest, DereferenceArrayName) {
    std::string output = captureOutput();
    EXPECT_TRUE(output.find("First element (*grades): 95") != std::string::npos)
        << "Should dereference the array name directly with *grades";
}

TEST(ArraysAsPointersTest, ArrayNamePlusOffset2) {
    std::string output = captureOutput();
    EXPECT_TRUE(output.find("Third element *(grades + 2): 72") != std::string::npos)
        << "Should use *(grades + 2) to access the third element";
}

TEST(ArraysAsPointersTest, ArrayNamePlusOffset4) {
    std::string output = captureOutput();
    EXPECT_TRUE(output.find("Fifth element *(grades + 4): 88") != std::string::npos)
        << "Should use *(grades + 4) to access the fifth element";
}
