//
// Created by bill on 9/24/2022.
//

#include <cstdint>
#include <cstring>
#include <iostream>
#include <gtest/gtest.h>

union FixedChar8 {
   char fixedString[9] = {};
   uint64_t asNumber;
};

TEST(UnionTest, fixedStrToUint64) {
   FixedChar8 testUnion;
   strncpy(testUnion.fixedString, "FixedStr", 8); // 0x 46 69 78 65 64 53 74 72
   std::cout << testUnion.fixedString << " => " << std::hex << "0x" << testUnion.asNumber;
   EXPECT_EQ(0x7274536465786946, testUnion.asNumber);
}

TEST(UnionTest, uint64ToFixedStr) {
   FixedChar8 testUnion;
   testUnion.asNumber = 0x7274536465786946;

   char testStr[9] = {};
   std::memcpy(testStr, &testUnion.asNumber, sizeof(testUnion.asNumber));

   std::cout << testStr << " == " << testUnion.fixedString;
   EXPECT_STREQ(testStr, testUnion.fixedString);
}
