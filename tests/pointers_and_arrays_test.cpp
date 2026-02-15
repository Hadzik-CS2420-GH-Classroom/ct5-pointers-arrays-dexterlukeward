#include <gtest/gtest.h>
#include <sstream>
#include <iostream>
#include "pointers_and_arrays.h"

// Helper: capture stdout from pointersAndArrays()
static std::string captureOutput() {
    std::stringstream buffer;
    std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());
    pointersAndArrays();
    std::cout.rdbuf(oldCout);
    return buffer.str();
}

// ==================== 1. Declaring Pointers and Arrays ====================

TEST(PointersAndArraysTest, PointerPointsToFirstElement) {
    std::string output = captureOutput();
    EXPECT_TRUE(output.find("Pointer points to: 10") != std::string::npos)
        << "Should declare a pointer to numbers[0] and print its dereferenced value";
}

// ==================== 2. Address of Array Elements ====================

TEST(PointersAndArraysTest, AddressOfElement0) {
    std::string output = captureOutput();
    EXPECT_TRUE(output.find("Address of numbers[0]:") != std::string::npos)
        << "Should print the address of numbers[0] using &";
}

TEST(PointersAndArraysTest, AddressOfElement1) {
    std::string output = captureOutput();
    EXPECT_TRUE(output.find("Address of numbers[1]:") != std::string::npos)
        << "Should print the address of numbers[1] using &";
}

TEST(PointersAndArraysTest, BytesBetweenElements) {
    std::string output = captureOutput();
    EXPECT_TRUE(output.find("Bytes between elements: 4") != std::string::npos)
        << "Should calculate byte difference between &numbers[1] and &numbers[0] as 4";
}

// ==================== 3. Dereferencing Pointers ====================

TEST(PointersAndArraysTest, DereferencedValue) {
    std::string output = captureOutput();
    EXPECT_TRUE(output.find("Dereferenced value: 42") != std::string::npos)
        << "Should dereference pValue to print 42";
}

TEST(PointersAndArraysTest, ModifyThroughPointer) {
    std::string output = captureOutput();
    EXPECT_TRUE(output.find("value is now: 99") != std::string::npos)
        << "Should modify value through *pValue = 99 and print it";
}

// ==================== 4. Pointer Arithmetic ====================

TEST(PointersAndArraysTest, PointerArithmeticPlus1) {
    std::string output = captureOutput();
    EXPECT_TRUE(output.find("start + 1 points to: 20") != std::string::npos)
        << "Should use *(start + 1) to access the second element";
}

TEST(PointersAndArraysTest, PointerArithmeticPlus3) {
    std::string output = captureOutput();
    EXPECT_TRUE(output.find("start + 3 points to: 40") != std::string::npos)
        << "Should use *(start + 3) to access the fourth element";
}

TEST(PointersAndArraysTest, WalkingWithPointer) {
    std::string output = captureOutput();
    EXPECT_TRUE(output.find("Walking with pointer: 10 20 30 40 50") != std::string::npos)
        << "Should use a pointer loop to print all elements";
}
