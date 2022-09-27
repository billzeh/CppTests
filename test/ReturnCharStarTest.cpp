//
// Created by bill on 9/27/2022.
//

#include <cstring>
#include <memory>
#include <string>
#include <gtest/gtest.h>

std::unique_ptr<char*> getCharString() {
   char raw[9] = {};
   std::strncpy(raw, "TestStr", 8);
   return std::make_unique<char*>(raw);  // Doesn't work
}

TEST(ReturnCharStarTest, testCharStringReturn) {
   auto str = getCharString();
   EXPECT_STRNE("TestStr", *str);
}

std::string getString() {
   char raw[9] = {};
   std::strncpy(raw, "TestStr", 8);
   return { raw };
}

TEST(ReturnCharStarTest, testStdStringReturn) {
   auto str = getString();
   EXPECT_STREQ("TestStr", str.c_str());
}
