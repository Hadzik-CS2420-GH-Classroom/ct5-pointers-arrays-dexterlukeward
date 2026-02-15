#include <gtest/gtest.h>
#include <sstream>
#include <iostream>
#include "pointers_as_arrays.h"

// Helper: capture stdout from pointersAsArrays()
static std::string captureOutput() {
    std::stringstream buffer;
    std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());
    pointersAsArrays();
    std::cout.rdbuf(oldCout);
    return buffer.str();
}

// ==================== 1. Bracket Indexing on a Pointer ====================

TEST(PointersAsArraysTest, BracketIndexPtr0) {
    std::string output = captureOutput();
    EXPECT_TRUE(output.find("Pointer access: ptr[0] = 100") != std::string::npos)
        << "Should print ptr[0] = 100 using bracket notation on a pointer";
}

TEST(PointersAsArraysTest, BracketIndexPtr2) {
    std::string output = captureOutput();
    EXPECT_TRUE(output.find("Pointer access: ptr[2] = 300") != std::string::npos)
        << "Should print ptr[2] = 300 using bracket notation on a pointer";
}

TEST(PointersAsArraysTest, BracketIndexPtr4) {
    std::string output = captureOutput();
    EXPECT_TRUE(output.find("Pointer access: ptr[4] = 500") != std::string::npos)
        << "Should print ptr[4] = 500 using bracket notation on a pointer";
}

// ==================== 2. Looping with Pointer [] Syntax ====================

TEST(PointersAsArraysTest, LoopPrintsAllElements) {
    std::string output = captureOutput();
    EXPECT_TRUE(output.find("ptr[0] = 100") != std::string::npos)
        << "Loop should print ptr[0] = 100";
    EXPECT_TRUE(output.find("ptr[1] = 200") != std::string::npos)
        << "Loop should print ptr[1] = 200";
    EXPECT_TRUE(output.find("ptr[2] = 300") != std::string::npos)
        << "Loop should print ptr[2] = 300";
    EXPECT_TRUE(output.find("ptr[3] = 400") != std::string::npos)
        << "Loop should print ptr[3] = 400";
    EXPECT_TRUE(output.find("ptr[4] = 500") != std::string::npos)
        << "Loop should print ptr[4] = 500";
}
